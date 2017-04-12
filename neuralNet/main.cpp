#include <iostream>
#include <Utils.hpp>
#include <Network.hpp>
#include <fstream>
#include <assert.h>

int main(){
  // init network
  std::vector<unsigned int> params({64, 32, 10});
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
  // train network
  for (auto i(0); i < train.size(); ++i) {
    net.feed(train[i]);
    net.back(train[i][64]);
    net.reset();
  }
  int trainCorrect(0);
  for (auto i(0); i < test.size(); ++i) {
    if (test[i][65] == net.feed(test[i]))
      trainCorrect++;
    net.reset();
  }
  net.dispose();
  return 0;
}
