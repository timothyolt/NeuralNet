// Copyright 2017 timothyolt.

#include <algorithm>
#include <cmath>
#include "Cluster.hpp"
#include "Utils.hpp"

using nnet::Cluster;

Cluster::Cluster() : id(Utils::makeId()), backward(0), forward(0) { }

Cluster::Cluster(const Cluster &copy)
    : id(copy.id), backward(copy.backward.size()), forward(copy.forward.size()) {
  std::copy(copy.backward.begin(), copy.backward.end(), backward.begin());
  std::copy(copy.forward.begin(), copy.forward.end(), forward.begin());
}

void Cluster::setBackwardEdges(std::vector<Edge *> &backward) {
  Cluster::backward = backward;
}

void Cluster::pushForwardEdge(nnet::Edge *&forward) {
  Cluster::forward.push_back(forward);
}

void Cluster::reset() {
  in = 0;
  out = 0;
}

void Cluster::set(double in) {
 Cluster::in += in;
}

double Cluster::get() {
  return out;
}

void Cluster::feed() {
  double sigmoid(1 / (1 + std::exp(in)));
  out = sigmoid * (1 - sigmoid);
  for (auto i(0); i < forward.size(); ++i)
    forward[i]->destination->in += forward[i]->weight * out;
}
