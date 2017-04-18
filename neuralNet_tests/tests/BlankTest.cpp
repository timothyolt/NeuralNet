// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <Network.hpp>

TEST(BlankTest, BlankTest) {
  std::vector<unsigned int> params({2, 1});
  nnet::Network net(params);
  std::vector<int> inputs({ 16, 16 });
  net.feed(inputs);
  net.back(0);
  net.dispose();
  std::cout << std::endl << "return" << std::endl;
}
