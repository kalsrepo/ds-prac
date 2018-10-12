//
//  circular-queue.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/23/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "circular-queue.hpp"
#include <iostream>
#include <cmath>

using namespace std;

bool CircularQ::isFull()
{
    cout << "head :" << head << " tail : " << tail << '\n';

    return (tail == (head + 1 ) % _size);
}

bool CircularQ::isEmpty()
{
    cout << "head :" << head << " tail : " << tail << '\n';

    return (tail == head);
}

void CircularQ::enque(int value)
{
    if (!isFull()) {
        values.at(head)= value;
        head = (head + 1) % _size;

    }
    cout << "head :" << head << " tail : " << tail << '\n';
}

bool CircularQ::deque(int &value)
{
    if (!isEmpty()) {
        value = values[tail];
        tail = (tail + 1) % _size;
        return true;
    }
    cout << "head :" << head << " tail : " << tail << '\n';

    return false;
}

void testCirQ()
{
    CircularQ q(5);
    
    bool empty = q.isEmpty();
    bool full = q.isFull();
    cout << empty << " " << full << '\n';

    q.enque(1);
    q.enque(2);
    
    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';

    q.enque(3);
    q.enque(4);
    q.enque(5);
    
    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';
    
    int val;
    q.deque(val);
    
    cout << "val : " << val << '\n';

    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';
    
    q.deque(val);
    
    cout << "val : " << val << '\n';
    
    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';
    
    q.enque(6);
    q.enque(7);

    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';

    q.deque(val);
    q.deque(val);
    q.deque(val);
    q.deque(val);
    q.deque(val);
    
    empty = q.isEmpty();
    full = q.isFull();
    cout << empty << " " << full << '\n';

}