// Copyright 2017 timothyolt.

#include "Edge.hpp"

using nnet::Edge;

Edge::Edge() : origin(nullptr), destination(nullptr), weight(0) { }

Edge::Edge(const Edge &copy) : origin(copy.origin), destination(copy.destination), weight(copy.weight) {

}

Edge::Edge(Cluster* origin, Cluster* destination, double weight)
    : origin(origin), destination(destination), weight(weight) { }
