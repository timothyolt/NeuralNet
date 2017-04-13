// Copyright 2017 timothyolt.

#ifndef NEURALNET_CLUSTER_HPP_
#define NEURALNET_CLUSTER_HPP_

#include <vector>
#include "Edge.hpp"

namespace nnet {
class Edge;
class Cluster {
 private:
  unsigned int id;
  std::vector<Edge*> backward;
  std::vector<Edge*> forward;
  double in;
  double out;
  double gradient;

 public:

  Cluster();

  Cluster(const Cluster& copy);

  void setBackwardEdges(std::vector<Edge *> &backward);

  void pushForwardEdge(Edge *&forward);

  void reset();

  void set(double in);

  double get();

  void feed();

  void grade();

  void grade(double desired);

  void update();
};
}

#endif  // NEURALNET_CLUSTER_HPP_
