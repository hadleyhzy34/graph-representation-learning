cmake_minimum_required(VERSION 3.8)
project(graph_representational_leaning)

add_library(graph_representation src/graph_representation/graph.cpp)
target_compile_features(graph_representation PUBLIC cxx_std_11)

#add_library(graph_representation src/graph_representation/graph.c)
#target_compile_features(graph_representation PUBLIC cxx_std_11)

add_library(dfs src/search/dfs.cpp)
target_compile_features(dfs PUBLIC cxx_std_11)

add_library(bfs src/search/bfs.cpp)
target_compile_features(bfs PUBLIC cxx_std_11)


add_compile_options(-ggdb)
add_executable(main src/main.cpp)
target_link_libraries(main bfs)

add_executable(graph_set src/graph_representation/graph_set.cpp)

add_executable(graph_unordered_set src/graph_representation/graph_unset.cpp)

