// Copyright 2017 Timothy Oltjenbruns.

#ifndef NEURALNET_SHARED_UTILS_HPP_
#define NEURALNET_SHARED_UTILS_HPP_

#include "string"

namespace nnet {
static unsigned int ID(0);
class Utils {
 public:
  static std::string helloWorld() {
    return "Hello Neural Net World!";
  }
  static unsigned int makeId() {
    return ID++;
  }
};
}


#endif // NEURALNET_SHARED_UTILS_HPP_
