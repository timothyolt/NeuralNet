#include <iostream>
#include <Utils.hpp>
#include <fstream>
#include <assert.h>
#include <Network.hpp>

int main(){
  // init network
  std::vector<unsigned int> params({64, 128, 10});
  nnet::Network net(params);
  // load samples
  std::ifstream optdigits_train("./../data/optdigits_train.txt");
  std::ifstream optdigits_test("./../data/optdigits_test.txt");
  if (!optdigits_train.is_open()) {
    std::cout << "Missing ./../data/optdigits_train.txt" << std::endl;
    return 1;
  }
  auto train(nnet::Utils::prepareInputs(optdigits_train, 3823, 65));
  optdigits_train.close();
  if (!optdigits_test.is_open()) {
    std::cout << "Missing ./../data/optdigits_test.txt" << std::endl;
    return 1;
  }
  auto test(nnet::Utils::prepareInputs(optdigits_test, 1797, 65));
  optdigits_train.close();
  // epoch
  for (auto j(0); j < 25; ++j) {
    // train network
    for (auto i(0); i < train.size(); ++i) {
      net.feed(train[i]);
      net.back(train[i][64]);
      net.reset();
    }
    // test network
    int testCorrect(0);
    for (auto i(0); i < test.size(); ++i) {
      if (test[i][64] == net.feed(test[i]))
        testCorrect++;
      net.reset();
    }
    std::cout << testCorrect << std::endl;
  }
  net.dispose();
  return 0;
}
