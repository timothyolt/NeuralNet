cmake_minimum_required(VERSION 3.6)
project(neuralNet_shared)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Utils.hpp)

add_library(neuralNet_shared STATIC ${SOURCE_FILES})
set_target_properties(neuralNet_shared PROPERTIES LINKER_LANGUAGE CXX)
