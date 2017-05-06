// Copyright 2017 timothyolt.

#ifndef NEURALNET_NETWORK_HPP_
#define NEURALNET_NETWORK_HPP_

#include <iostream>
#include "Layer.hpp"

namespace nnet {
class Network {
 private:
  std::vector<Layer> layers;

 public:
  Network();

  Network(std::vector<unsigned int>& layerSizes);

  void reset();

  int feed(std::vector<int> &in);

  void back(int desired, double learnRate);

  void dispose();

  friend std::ostream &operator<<(std::ostream &os, const Network &network) {
    for (int i = 0; i < network.layers.size() - 1; ++i)
      os << network.layers[i] << std::endl;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Network &network) {
    for (int i = 0; i < network.layers.size() - 1; ++i)
      is >> network.layers[i];
    return is;
  }
};
}


#endif  // NEURALNET_NETWORK_HPP_