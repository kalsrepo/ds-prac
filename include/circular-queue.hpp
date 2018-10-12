//
//  circular-queue.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/23/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef circular_queue_hpp
#define circular_queue_hpp

#include <stdio.h>
#include <vector>

class CircularQ {
    int _size;
    int head;
    int tail;
    std::vector<int> values;
    
public:
    CircularQ (int size) : _size(size), head(0), tail(0) {
        for (int i = 0; i < _size; i++)
            values.push_back(-1);
    }
    void enque(int value);
    bool deque(int &value);
    bool isFull();
    bool isEmpty();
    void clear();
};

void testCirQ();

#endif /* circular_queue_hpp */
