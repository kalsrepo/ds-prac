//
//  gencpp.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/29/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "gencpp.hpp"
#include <iostream>

using namespace std;

struct A {
    int i;
};

struct B {
    int i;
};

struct node {
    struct A *a;
    struct B *b;
    
    node ()
    {
        a = new A();
        b = new B();
    }
    
    node (int i, int j)
    {
        a = new A();
        a->i = i;
        
        b = new B();
        b->i = j;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const node& np)
    {
        os << np.a->i << " " << np.b->i;
        return os;
    }
    struct node * copyNode();
};

struct node * node::copyNode()
{
    struct node *n = new node();
    n->a = new A(*a);
    n->b = new B(*b);
    
    return n;
}

void testGenCpp ()
{
    struct node *n1 = new node(10, 20);
    
    struct node *n2 = n1->copyNode();
   
    cout << "n1 : " << *n1 << "\nn2 : " << *n2 << endl;
}
