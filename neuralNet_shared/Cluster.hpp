// Copyright 2017 timothyolt.

#ifndef NEURALNET_CLUSTER_HPP_
#define NEURALNET_CLUSTER_HPP_

#include <vector>
#include <iostream>

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

  friend std::ostream &operator<<(std::ostream &os, const Edge &edge) {
    os << edge.weight;
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Edge &edge) {
    double temp;
    is >> temp;
    edge.weight = temp;
    return is;
  }
};
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

  void update(double learnRate);

  friend std::ostream &operator<<(std::ostream &os, const Cluster &cluster) {
    for (auto i(0); i < cluster.forward.size(); ++i)
      os << *cluster.forward[i] << ',';
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Cluster &cluster) {
    for (auto i(0); i < cluster.forward.size(); ++i)
      is >> *cluster.forward[i];
    return is;
  }
};
}

#endif  // NEURALNET_CLUSTER_HPP_
