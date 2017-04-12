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
  auto out(net.feed(train[0]));
  std::vector<double> desired({1, 0, 0, 0, 0, 0, 0, 0, 0, 0});
  net.back(train[0][64]);
  net.dispose();
  return 0;
}
