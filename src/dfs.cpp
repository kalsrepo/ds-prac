//
//  dfs.cpp
//  C++ Data structures
//
//  Created by Kallol Banerjee on 5/10/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include <iostream>
#include <stack>
#include "dfs.hpp"

dfs::dfs(Graph &G, int s) : _S(s), visited(G.V(), false), edgeTo(G.V(), -1)
{
    depthFirstSearch(G, s);
    
    for (std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++) {
        std::cout << (it - visited.begin()) << " = " << (*it ? "true" : "false") << std::endl;
    }

    for (std::vector<int>::iterator it = edgeTo.begin(); it != edgeTo.end(); it++) {
        std::cout << (it - edgeTo.begin()) << " = " << *it << std::endl;
    }
}

bool dfs::hasPathTo (int v)
{
    return visited[v];
}

std::stack<int> dfs::pathTo(int v)
{
    std::stack<int> paths;
    
    if (!hasPathTo(v)) return paths;
    
    int p = v;
    while (p != _S) {
        p = edgeTo[p];
        paths.push(p);
    }
    
    return paths;
}

void dfs::depthFirstSearch (Graph &G, int s)
{
    visited[s] = true;
    std::vector<int> e = G.adj(s);
    for (std::vector<int>::iterator it = e.begin(); it != e.end(); it++) {
        if (!visited[*it]) {
            depthFirstSearch(G, *it);
            edgeTo[*it] = s;
        }
    }
}

void dfs::depthFirstSearch1 (Graph &G, int s)
{
    visited[s] = true;
    std::vector<int> e = G.adj(s);
    
    for (std::vector<int>::iterator it = e.begin(); it != e.end(); it++) {
        if (!visited[*it]) {
            depthFirstSearch(G, *it);
            edgeTo[*it] = s;
        }
    }
}