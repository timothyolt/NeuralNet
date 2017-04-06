cmake_minimum_required(VERSION 3.6)
project(neuralNet)

add_executable(run_neuralNet main.cpp)

target_link_libraries(run_neuralNet neuralNet_shared)
