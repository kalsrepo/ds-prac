//
//  graph.cpp
//  C++ Data structures
//
//  Created by Kallol Banerjee on 5/10/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include <iostream>
#include "graph.hpp"

using namespace std;

Graph::Graph(int v) : noOfVertex(v), adjList(v)
{
    //cout << "no of vertex : " << v << endl;
}

// return no of vertext
unsigned long Graph::V()
{
    return adjList.size();
}

// return no of edge
unsigned long Graph::E()
{
    int noOfEdge = 0;
    int i = 0;
    
    for (std::vector<std::vector<int>>::iterator it = adjList.begin(); it != adjList.end(); ++it, ++i) {
        //cout << "vertext : "<< i << " : " << adjList[i].size() << endl;
        noOfEdge += it->size();
    }
    
    return noOfEdge/2;
}

// add edge
bool Graph::addEdge(int v, int w)
{
    if (v >= noOfVertex || w >= noOfVertex) {
        return false;
    }
    
    adjList[v].push_back(w);
    adjList[w].push_back(v);
    
    return true;
}

// Iterate though the adjacency of a vertext
std::vector<int> Graph::adj(int v)
{
    return adjList[v];
}

void Graph::print()
{
    int i = 0;
    
    for (std::vector<std::vector<int>>::iterator it = adjList.begin(); it != adjList.end(); ++it, ++i) {
        for (std::vector<int>::iterator jt = it->begin(); jt != it->end(); ++jt) {
            cout << i << " - " << *jt <<endl;
        }
    }
}
