cmake_minimum_required(VERSION 3.7)
project(NeuralNet)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules-sonar")

if(CMAKE_BUILD_TYPE STREQUAL "Analysis")
    include(SonarAnalysis)
    ADD_TARGET_SONAR("Analysis" "neuralNet_shared" "neuralNet_tests" "neuralNet_tests/tests" "run_tests")
endif()

include_directories(neuralNet_shared)

add_subdirectory(neuralNet)
add_subdirectory(neuralNet_shared)
add_subdirectory(neuralNet_tests)