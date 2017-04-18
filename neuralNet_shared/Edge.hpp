// Copyright 2017 timothyolt.

#ifndef NEURALNET_EDGE_HPP_
#define NEURALNET_EDGE_HPP_

#include "Cluster.hpp"

namespace nnet {
class Cluster;
class Edge {
 private:

 public:
  Cluster* origin;
  Cluster* destination;

  double weight;

  Edge();

  Edge(const Edge & copy);

  Edge(Cluster* origin, Cluster* destination, double weight);
};
}

#endif  // NEURALNET_EDGE_HPP_
