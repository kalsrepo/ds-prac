cmake_minimum_required(VERSION 3.5)
project (testds)

#Bring the headers, such as Student.h into the project
include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

SET(CMAKE_CXX_FLAGS  "-std=c++11")


add_executable(testds ${SOURCES})

target_link_libraries(testds pthread)
#add_executable(testds src/ArraysStrings.cpp src/bfs.cpp src/bt.cpp src/bt-p.cpp src/circular-queue.cpp src/dfs.cpp src/dp.cpp src/gencpp.cpp src/graph.cpp src/linkedlist.cpp src/lru.cpp src/main.cpp src/maxsumparallel.cpp src/minpq.cpp src/mm.cpp src/oo.cpp src/ordered-map.cpp src/pq.cpp src/sort.cpp src/testbt.cpp src/testgraph.cpp src/tictac.cpp src/trie.cpp)


