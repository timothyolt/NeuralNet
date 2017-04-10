// Copyright 2017 timothyolt.

#ifndef NEURALNET_EDGECLUSTER_HPP_
#define NEURALNET_EDGECLUSTER_HPP_

#include <vector>
#include "Edge.hpp"
#include "Node.hpp"

namespace nnet {
class Edge;
class Cluster {
 private:
  unsigned int id;
  Node node;
  std::vector<Edge*> backward;
  std::vector<Edge*> forward;

 public:

  Cluster();

  Cluster(const Cluster& copy);

  void setBackward(std::vector<Edge *> &backward);

  void forwardPushBack(Edge *&forward);

};
}

#endif  // NEURALNET_EDGECLUSTER_HPP_
