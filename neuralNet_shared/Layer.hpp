// Copyright 2017 timothyolt.

#ifndef NEURALNET_LAYER_HPP_
#define NEURALNET_LAYER_HPP_

#include <iostream>
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

  void set(std::vector<int> &in);

  std::vector<double> get();

  void feed();

  void grade();

  void grade(std::vector<double> &desired);

  void update(double learnRate);

  void dispose();

  friend std::ostream &operator<<(std::ostream &os, const Layer &layer) {
    os << *layer.bias << std::endl;
    for (auto i(0); i < layer.clusters.size(); ++i)
      os << *layer.clusters[i] << std::endl;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Layer &layer) {
    is >> *layer.bias;
    for (auto i(0); i < layer.clusters.size(); ++i)
      is >> *layer.clusters[i];
    return is;
  }
};
}

#endif  // NEURALNET_LAYER_HPP_
