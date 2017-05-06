// Copyright 2017 Timothy Oltjenbruns.

#ifndef NEURALNET_SHARED_UTILS_HPP_
#define NEURALNET_SHARED_UTILS_HPP_

#include <locale>
#include <iostream>
#include <vector>
#include "string"
#include "Network.hpp"

struct csv : std::ctype<char> {
  csv(char* delimiters, unsigned int count) : std::ctype<char>([delimiters, count]() -> const mask * {
    static mask rc[table_size];
    for (auto i(0); i < count; ++i)
      rc[delimiters[i]] = std::ctype_base::space;
    rc['\n'] = std::ctype_base::space;
    rc['\r'] = std::ctype_base::space;
    return &rc[0];
  }()) { }
};

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

  inline static std::vector<std::vector<int>> prepareInputs(std::istream& in, unsigned int setCount, unsigned int inputCount) {
    std::vector<std::vector<int>> set(setCount);
    char delimiters[] = {','};
    in.imbue(std::locale(in.getloc(), new csv(delimiters, 1)));
    int input;
    for (auto i(0); in >> input; ++i) {
      if (i % inputCount == 0)
        set[i / inputCount] = std::vector<int>(inputCount);
      set[i / inputCount][i % inputCount] = input;
    }
    return set;
  }

  inline static void prepareWeights(std::istream& in, Network &network) {
    char delimiters[] = {','};
    in.imbue(std::locale(in.getloc(), new csv(delimiters, 1)));
    in >> network;
  }
};
}

#endif // NEURALNET_SHARED_UTILS_HPP_
