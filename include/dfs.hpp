//
//  dfs.hpp
//  C++ Data structures
//
//  Created by Kallol Banerjee on 5/10/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef dfs_hpp
#define dfs_hpp

#include <stdio.h>
#include <stack>

#include "graph.hpp"

class dfs {
    int _S;
    std::vector<bool> visited;
    std::vector<int> edgeTo;
    
public:
    dfs(Graph &G, int s);
    
    bool hasPathTo (int v);
    std::stack<int> pathTo(int v);
    
private:
    void depthFirstSearch (Graph &G, int s);
    void depthFirstSearch1 (Graph &G, int s);

};

#endif /* dfs_hpp */
