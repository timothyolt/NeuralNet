// Copyright 2017 Timothy Oltjenbruns.

#include <gtest/gtest.h>
#include <Network.hpp>

TEST(BlankTest, BlankTest) {
  std::vector<unsigned int> params({64, 32, 10});
  nnet::Network net(params);
  std::vector<double> inputs({
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                       1, 1, 1, 1, 1, 1, 1, 1,
                                   });
  auto out(net.feed(inputs));
  std::vector<double> desired({0, 0, 0, 0, 0, 0, 0, 0, 0, 1});
  net.back(desired);
  net.dispose();
  std::cout << std::endl << "return" << std::endl;
}
