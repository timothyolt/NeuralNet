// Copyright 2017 timothyolt.

#ifndef NEURALNET_LAYER_HPP_
#define NEURALNET_LAYER_HPP_

#include "Cluster.hpp"

namespace nnet {
class Layer {
 private:
  std::vector<Cluster*> clusters;

  Cluster* bias;

 public:
  Layer();

  Layer(const Layer& copy);

  explicit Layer(unsigned int size);

  void link(Layer *backward);

  void reset();

  void set(std::vector<double> &in);

  std::vector<double> get();

  void feed();

  void dispose();
};
}

#endif  // NEURALNET_LAYER_HPP_
