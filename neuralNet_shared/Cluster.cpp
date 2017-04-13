// Copyright 2017 timothyolt.

#include <algorithm>
#include <cmath>
#include "Cluster.hpp"
#include "Utils.hpp"

using nnet::Cluster;

Cluster::Cluster() : id(Utils::makeId()), backward(0), forward(0), in(0), out(0), gradient(0) { }

Cluster::Cluster(const Cluster &copy)
    : id(copy.id), backward(copy.backward.size()), forward(copy.forward.size())
    , in(0), out(0), gradient(0) {
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
  gradient = 0;
}

void Cluster::set(double value) {
  in += value;
  out += value;
}

double Cluster::get() {
  return out;
}

void Cluster::feed() {
  out = 1 / (1 + std::exp(-in));
  for (auto i(0); i < forward.size(); ++i)
    forward[i]->destination->in += forward[i]->weight * out;
}

void Cluster::grade() {
  for (auto i(0); i < forward.size(); ++i)
    gradient += forward[i]->weight * forward[i]->destination->gradient;
  gradient *= out * (1 - out);
}

void Cluster::grade(double desired) {
  gradient = (desired - out) * out * (1 - out);
}

void Cluster::update() {
  for (auto i(0); i < backward.size(); ++i)
    backward[i]->weight += 0.9 * backward[i]->origin->out * gradient;
}
