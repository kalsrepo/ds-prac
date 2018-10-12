//
//  bt.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 5/19/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef bt_hpp
#define bt_hpp

#include <stdio.h>
#include <vector>
#include <string>

template <typename T>
class BT;

template <typename T>
class node {
    int size;
    
    friend class BT<T>;
    
public:
    int key;

    class node<T> *right, *left, *next;
    
    node(T key);
    std::string visit();
    //~node();
};

template <typename T>
class BT {
    class node<T> *root;
    
    bool search (class node<T> *node, T key);
    class node<T> *insert (class node<T> *node, T key);
    class node<T>*  del (class node<T> *node, T key);
    void inorder (class node<T> *n);
    void preorder (class node<T> *n);
    void postorder (class node<T> *n);
    class node<T> *derefMin(class node<T> *n);
    class node<T> *min(class node<T> *n);
    class node<T> *deleteMin(class node<T> *n);
    int rank(class node<T> *n, T key);
    class node<T> *floor(class node<T> *n, T key);
    int maxDepth(class node<T> *node);
    void mirror(class node<T> *n);
    void doubleT(class node<T> *n);
    void nextNode (class node<T> *n, T key, class node<T> **res, bool *found);
    
    void makeList (class node<T> *n, class node<T> **head, class node<T> **next);
    class node<T> * makeList1 (class node<T> *n);

    
public:
    BT();
    BT(std::vector<T> &_keys);
    ~BT();
    
    void insert(T key);
    void del(T key);
    bool search(T key);
    int rank(T key);
    void deleteMin();
    class node<T> *floor(T key);
    int maxDepth();
    
    void inorder();
    void preorder();
    void postorder();

    void mirror();
    void doubleT();
    
    void makeList (class node<T> **head);
    class node<T> * makeList1 ();

    T nextKey(T key);

};

void testbt();

#endif /* bt_hpp */
