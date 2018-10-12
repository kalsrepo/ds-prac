//
//  bfs.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 5/12/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef bfs_hpp
#define bfs_hpp

#include <stdio.h>
#include <stack>

#include "graph.hpp"

class bfs {
    int _S;
    std::vector<bool> visited;
    std::vector<int> edgeTo;
    std::vector<int> distTo;
    
public:
    bfs(Graph &G, int s);
    
    bool hasPathTo (int v);
    std::stack<int> pathTo(int v);
    
private:
    void breathFirstSearch (Graph &G, int s);
    void breathFirstSearch1(Graph &G, int s);

};


#endif /* bfs_hpp */
