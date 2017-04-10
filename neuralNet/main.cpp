#include <iostream>
#include <Utils.hpp>
#include <Network.hpp>

int main(){
  std::cout << Utils::helloWorld() << std::endl;
  std::vector<unsigned int> params({16, 8, 4});
  nnet::Network net(params);
  net.dispose();
  return 0;
}
