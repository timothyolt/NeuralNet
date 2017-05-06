// Copyright 2017 timothyolt.

#include <algorithm>
#include <climits>
#include "Layer.hpp"

using nnet::Layer;

Layer::Layer() : clusters(), bias(new Cluster()) { }

Layer::Layer(const Layer &copy) : clusters(copy.clusters.size()), bias(copy.bias) {
  std::copy(copy.clusters.begin(), copy.clusters.end(), clusters.begin());
}

Layer::Layer(unsigned int size) : clusters(), bias(new Cluster()) {
  bias->set(1);
  for (auto i(0); i < size; ++i)
    clusters.push_back(new Cluster());
}

void Layer::link(Layer *backward) {
  for (auto i(0); i < clusters.size(); ++i) {
    std::vector<Edge*> edges;
    edges.reserve(backward->clusters.size() + 1);
    auto biasEdge(new Edge(backward->bias, clusters[i], (rand() / (double) INT_MAX) * 0.4 - 0.2));
    backward->bias->pushForwardEdge(biasEdge);
    edges.push_back(biasEdge);
    for (auto j(0); j < backward->clusters.size(); ++j) {
      auto edge(new Edge(backward->clusters[j], clusters[i], (rand() / (double) INT_MAX) * 0.4 - 0.2));
      backward->clusters[j]->pushForwardEdge(edge);
      edges.push_back(edge);
    }
    clusters[i]->setBackwardEdges(edges);
  }
}

void Layer::reset() {
  bias->reset();
  bias->set(1);
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->reset();
}

void Layer::set(std::vector<int> &in) {
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->set(in[i] / 16.0);
}

std::vector<double> Layer::get() {
  std::vector<double> outputs(clusters.size());
  std::transform(clusters.begin(), clusters.end(), outputs.begin(), [](auto& cluster) {
    return cluster->get();
  });
  return outputs;
}

void Layer::feed() {
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->feed();
}

void Layer::grade() {
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->grade();
}

void Layer::grade(std::vector<double> &desired) {
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->grade(desired[i]);
}

void Layer::update(double learnRate) {
  for (auto i(0); i < clusters.size(); ++i)
    clusters[i]->update(learnRate);
}

void Layer::dispose() {
  delete bias;
  for (auto i(0); i < clusters.size(); ++i)
    delete clusters[i];
}