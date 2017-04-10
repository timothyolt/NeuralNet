// Copyright 2017 timothyolt.

#include <algorithm>
#include "Layer.hpp"

using nnet::Layer;

Layer::Layer() : clusters(), bias(nullptr) { }

Layer::Layer(const Layer &copy) : clusters(copy.clusters.size()), bias(copy.bias) {
  std::copy(copy.clusters.begin(), copy.clusters.end(), clusters.begin());
}

Layer::Layer(unsigned int size) : clusters(), bias(nullptr) {
  for (auto i(0); i < size; ++i)
    clusters.push_back(new Cluster());
}

void Layer::link(Layer *backward) {
  for (auto i(0); i < clusters.size(); ++i) {
    std::vector<Edge*> edges;
    edges.reserve(backward->clusters.size());
    for (auto j(0); j < backward->clusters.size(); ++j) {
      auto edge(new Edge(backward->clusters[j], clusters[i], 1.0));
      backward->clusters[j]->forwardPushBack(edge);
      edges.push_back(edge);
    }
    clusters[i]->setBackward(edges);
  }
}

void Layer::dispose() {
  delete bias;
  for (auto i(0); i < clusters.size(); ++i)
    delete clusters[i];
}
