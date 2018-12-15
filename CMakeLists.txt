cmake_minimum_required(VERSION 3.8)

project(VariablesContainer)

add_executable(VariableContainer ./src/main.cpp)

target_compile_features(VariableContainer PRIVATE cxx_std_17)
target_compile_options(VariableContainer PRIVATE -Wall)
