//
//  pq.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 5/12/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "pq.hpp"


template <typename T>
void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

void testPQ () {
    std::priority_queue<int> q;
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);
    
    print_queue(q);
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
    
    print_queue(q2);
    
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
    
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);
    
    print_queue(q3);
    
}