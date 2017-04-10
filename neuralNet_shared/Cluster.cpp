// Copyright 2017 timothyolt.

#include <algorithm>
#include "Cluster.hpp"
#include "Utils.hpp"

using nnet::Cluster;

Cluster::Cluster() : id(Utils::makeId()), node(), backward(0), forward(0) { }

Cluster::Cluster(const Cluster &copy)
    : id(copy.id), node(copy.node), backward(copy.backward.size()), forward(copy.forward.size()) {
  std::copy(copy.backward.begin(), copy.backward.end(), backward.begin());
  std::copy(copy.forward.begin(), copy.forward.end(), forward.begin());
}

void Cluster::setBackward(std::vector<Edge *> &backward) {
  Cluster::backward = backward;
}

void Cluster::forwardPushBack(nnet::Edge *&forward) {
  Cluster::forward.push_back(forward);
}
