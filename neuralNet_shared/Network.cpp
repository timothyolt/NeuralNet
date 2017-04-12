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

int Network::feed(std::vector<int> &in) {
  layers.front().set(in);
  for (auto i(0); i < layers.size(); ++i)
      layers[i].feed();
  auto outVector(layers.back().get());
  double max(outVector.front());
  int maxI(0);
  for (auto i(0); i < outVector.size(); ++i)
    if (outVector[i] > max){
      max = outVector[i];
      maxI = i;
    }
  return maxI;
}

void Network::back(int desired) {
  std::vector<double> desiredVector(10);
  for (auto j(0); j < 10; ++j)
    desiredVector[j] = 0;
  desiredVector[desired] = 1;

  layers.back().grade(desiredVector);
  for (auto i(layers.size() - 1); i >= 1; --i)
    layers[i].grade();
  for (auto i(1); i < layers.size(); ++i)
    layers[i].update();
}

void Network::dispose() {
  std::for_each(layers.begin(), layers.end(), [](auto l) { l.dispose(); });
}
