//
//  graph.hpp
//  C++ Data structures
//
//  Created by Kallol Banerjee on 5/10/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <vector>
#include <map>
#include <string>

class Graph {
    int noOfVertex;
    std::vector<std::vector<int>> adjList;
    
public:
    // constructor
    Graph(int v);
    
    // return no of vertext
    unsigned long V();
    
    // return no of edge
    unsigned long E();
    
    // add edge
    bool addEdge(int v, int w);
    
    // Iterate though the adjacency of a vertext
    std::vector<int> adj(int v);
    
    void print();
};

#endif /* graph_hpp */
