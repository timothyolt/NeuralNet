// Copyright 2017 timothyolt.

#include <algorithm>
#include "Network.hpp"

using nnet::Network;

Network::Network() { }

Network::Network(std::vector<unsigned int>& layerSizes) {
  layers.reserve(layerSizes.size());
  layers.emplace_back(layerSizes.front());
  for (auto i(1); i < layerSizes.size(); ++i){
    layers.emplace_back(layerSizes[i]);
    layers[i].link(&layers[i - 1]);
  }
}

void Network::reset() {
  for (auto i(0); i < layers.size(); ++i)
    layers[i].reset();
}

std::vector<double> Network::feed(std::vector<double> &in) {
  layers.front().set(in);
  for (auto i(0); i < layers.size(); ++i)
      layers[i].feed();
  return layers.back().get();
}

void Network::dispose() {
  std::for_each(layers.begin(), layers.end(), [](auto l) { l.dispose(); });
}
