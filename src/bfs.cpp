//
//  bfs.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 5/12/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "bfs.hpp"
#include <iostream>
#include <queue>

bfs::bfs(Graph &G, int s) : _S(s), visited(G.V(), false), edgeTo(G.V(), -1), distTo(G.V(), -1)
{
    breathFirstSearch(G, s);
    
    for (std::vector<bool>::iterator it = visited.begin(); it != visited.end(); it++) {
        std::cout << (it - visited.begin()) << " = " << (*it ? "true" : "false") << std::endl;
    }
    
    for (std::vector<int>::iterator it = edgeTo.begin(); it != edgeTo.end(); it++) {
        std::cout << (it - edgeTo.begin()) << " = " << *it << std::endl;
    }

    for (std::vector<int>::iterator it = distTo.begin(); it != distTo.end(); it++) {
        std::cout << (it - distTo.begin()) << " = " << *it << std::endl;
    }
}

bool bfs::hasPathTo (int v)
{
    return visited[v];
}

std::stack<int> bfs::pathTo(int v)
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

void bfs::breathFirstSearch (Graph &G, int s)
{
    std::queue<int> e;
    int dist = 0;

    visited[s] = true;
    edgeTo[s] = s;
    distTo[s] = dist;
    e.push(s);
    
    while (!e.empty()) {
        int n = e.front();
        e.pop();
        dist++;
        std::vector<int> edges = G.adj(n);
        for (std::vector<int>::iterator it = edges.begin(); it != edges.end(); it++) {
            if (!visited[*it]) {
                e.push(*it);
                visited[*it] = true;
                edgeTo[*it] = n;
                distTo[*it] = dist;
            }
        }
    }
}

void bfs::breathFirstSearch1(Graph &G, int s)
{
    std::queue<int> e;
    int dist = 0;
    
    visited[s] = true;
    distTo[s] = dist;
    edgeTo[s] = s;
    
    e.push(s);
    
    while (!e.empty()) {
        int n = e.front();
        e.pop();
        dist++;
        
        std::vector<int> edges = G.adj(n);
        
        for (std::vector<int>::iterator it = edges.begin(); it != edges.end(); it++) {
            if (!visited[*it]) {
                e.push(*it);
                visited[*it] = true;
                edgeTo[*it] = n;
                distTo[*it] = dist;
            }
        }
    }
    
}