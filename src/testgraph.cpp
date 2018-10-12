//
//  testgraph.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 5/10/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "testgraph.hpp"

#include <iostream>
#include "graph.hpp"
#include "dfs.hpp"
#include "bfs.hpp"

using namespace std;

static Graph graph1()
{
    Graph G(4);
    
    cout << "no of vertext : " << G.V() << endl;
    
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(0, 3);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    
    cout << "no of edges : " << G.E() << endl;
    
    G.print();

    return G;
}

void dfs_test()
{
    cout << "dfs_test :" << endl;

    Graph G = graph1();
    
    cout << "DFS for node : 0 " << endl;
    dfs d0(G, 0);

    cout << "DFS path to node : 3 " << endl;
    std::stack<int> path0 = d0.pathTo(3);
    
    while (!path0.empty()) {
        std::cout << ' ' << path0.top();
        path0.pop();
    }
    std::cout << "\n";

    cout << "DFS for node : 1 " << endl;
    dfs d1(G, 1);
    
    cout << "DFS path to node : 3 " << endl;
    std::stack<int> path = d1.pathTo(3);
    
    cout << "3 ";
    while (!path.empty()) {
        std::cout << "-> " << path.top();
        path.pop();
    }
    std::cout << "\n";
}

void bfs_test()
{
    cout << "bfs_test :" << endl;

    Graph G = graph1();
    
    cout << "BFS for node : 0 " << endl;
    bfs d0(G, 0);

    cout << "BFS for node : 1 " << endl;
    bfs d1(G, 1);
    
    cout << "BFS path to node : 3 " << endl;
    std::stack<int> path = d1.pathTo(3);
    
    cout << "3 ";
    while (!path.empty()) {
        std::cout << "-> " << path.top();
        path.pop();
    }
    std::cout << "\n";

}