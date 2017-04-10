// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <Network.hpp>

TEST(BlankTest, BlankTest) {
  std::vector<unsigned int> params({16, 8, 4});
  nnet::Network net(params);
  net.dispose();
  std::cout << std::endl << "return" << std::endl;
}
