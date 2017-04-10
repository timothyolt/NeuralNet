// Copyright 2017 timothyolt.

#include <algorithm>
#include "Network.hpp"

nnet::Network::Network() { }

nnet::Network::Network(std::vector<unsigned int>& layerSizes) {
  layers.reserve(layerSizes.size());
  layers.emplace_back(layerSizes.front());
  for (auto i(1); i < layerSizes.size(); ++i){
    layers.emplace_back(layerSizes[i]);
    layers[i].link(&layers[i - 1]);
  }
}

void nnet::Network::dispose() {
  std::for_each(layers.begin(), layers.end(), [](auto l) { l.dispose(); });
}
