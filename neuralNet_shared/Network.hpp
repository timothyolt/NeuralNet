// Copyright 2017 timothyolt.

#ifndef NEURALNET_NETWORK_HPP_
#define NEURALNET_NETWORK_HPP_

#include "Layer.hpp"

namespace nnet {
class Network {
 private:
  std::vector<Layer> layers;

 public:
  Network();

  Network(std::vector<unsigned int>& layerSizes);

  void reset();

  std::vector<double> feed(std::vector<int> &in);

  void back(int desired);

  void dispose();
};
}


#endif  // NEURALNET_NETWORK_HPP_
