#include <iostream>
#include <Utils.hpp>
#include <fstream>
#include <iomanip>

void loadWeights(nnet::Network &network);

bool loadSamples(std::vector<std::vector<int>>* train, std::vector<std::vector<int>>* test);

void save(nnet::Network &net);

double adjustLearnRate(int epoch, double rate, double accuracy);

int main(){
  // init network
  std::vector<unsigned int> params({64, 128, 10});
  nnet::Network net(params);
  loadWeights(net);
  // load samples
  std::vector<std::vector<int>> train;
  std::vector<std::vector<int>> test;
  if (loadSamples(&train, &test))
    return 1;
  // epoch
  double trainAccuracy(0);
  double testAccuracy(0);
  double learnRate(0);  // don't do anything first run, just see how we do.
  for (auto epoch(0); epoch < 10000; ++epoch) {
    // train network
    int trainCorrect(0);
    for (auto i(0); i < train.size(); ++i) {
      if (train[i][64] == net.feed(train[i]))
        trainCorrect++;
      net.back(train[i][64], learnRate);
      net.reset();
    }
    trainAccuracy = trainCorrect / 38.2;
    // test network
    int testCorrect(0);
    for (auto i(0); i < test.size(); ++i) {
      if (test[i][64] == net.feed(test[i]))
        testCorrect++;
      net.reset();
    }
    testAccuracy = testCorrect  / 17.97;
    // output status
    std::cout
        << " Epoch: "  << std::setw(3) << epoch
        << " Train: " << std::setw(7) << trainAccuracy
        << " Test: "  << std::setw(7) << testAccuracy
        << " Learn Rate: "  << std::setw(7) << learnRate
      << std::endl;
    // adjust learn rate
    learnRate = adjustLearnRate(epoch, learnRate, trainAccuracy);
  }
  save(net);
  net.dispose();
  return 0;
}

void loadWeights(nnet::Network &net) {
  std::ifstream paramsFile("./../data/params.txt");
  if (paramsFile.is_open()) {
    nnet::Utils::prepareWeights(paramsFile, net);
    paramsFile.close();
  }
}

bool loadSamples(std::vector<std::vector<int>>* train, std::vector<std::vector<int>>* test) {
  std::ifstream trainFile("./../data/optdigits_train.txt");
  std::ifstream testFile("./../data/optdigits_test.txt");
  if (!trainFile.is_open()) {
    std::cout << "Missing ./../data/optdigits_train.txt" << std::endl;
    return true;
  }
  *train = nnet::Utils::prepareInputs(trainFile, 3823, 65);
  trainFile.close();
  if (!testFile.is_open()) {
    std::cout << "Missing ./../data/optdigits_test.txt" << std::endl;
    return true;
  }
  *test = nnet::Utils::prepareInputs(testFile, 1797, 65);
  trainFile.close();
  return false;
}

double adjustLearnRate(int epoch, double rate, double accuracy) {
  rate = accuracy < 50
              ? 0.75
              : accuracy < 75
                ? 0.5
                : accuracy < 90
                  ? 0.25
                  : accuracy < 95
                    ? 0.20
                    : accuracy < 98
                      ? 0.15
                      : 0.1;
  if (epoch > 500)
    rate /= 2.0;
  return rate;
}

void save(nnet::Network &net) {
  std::ofstream paramsFile("./../data/params.txt");
  paramsFile << net;
}
