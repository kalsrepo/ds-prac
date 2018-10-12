//
//  bt-p.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/13/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "bt-p.hpp"

#include <iostream>

using namespace std;

template <typename T>
node<T>::node(T _key): key(_key), size(1), right(NULL), left(NULL)
{
    
}


template <typename T>
string node<T>::visit()
{
    string s = "(" + to_string(key) + ":" + to_string(size) + ")";
    return s;
}

template <typename T>
BT<T>::BT(): root(NULL)
{
    
}

template <typename T>
BT<T>::~BT()
{
    
}

template <typename T>
BT<T>::BT(std::vector<T> &_keys): root(NULL)
{
    for(std::vector<int>::iterator itr = _keys.begin(); itr != _keys.end(); itr++) {
        insert(*itr);
    }
}

template <typename T>
class node<T> * BT<T>::insert(class node<T> *n, T key)
{
    if (n == NULL) return new node<T>(key);
    
    if (n->key > key) {
        n->left = insert(n->left, key);
    } else if (n->key < key) {
        n->right = insert(n->right, key);
    }
    
    return n;
}

template <typename T>
void BT<T>::insert(T key)
{
    root = insert(root, key);
}

template <typename T>
class node<T> * BT<T>::min(class node<T> *n)
{
    if (!n || n->left == NULL) return n;
    
    return min(n->left);
}

template <typename T>
class node<T> * BT<T>::deleteMin(class node<T> *n)
{
    if (n->left == NULL) {
        class node<T> *t = n->right;
        delete n;
        return t;
    }
    
    n->left = deleteMin(n->left);
    return n;
}


template <typename T>
void BT<T>::deleteMin()
{
    root = deleteMin(root);
}

template <typename T>
class node<T> * BT<T>::derefMin(class node<T> *n)
{
    if (n->left == NULL) {
        cout << "deref : " << n->key << endl;
        return n->right;
    }
    n->left = derefMin(n->left);
    return n;
}

template <typename T>
class node<T>* BT<T>::del(class node<T> *n, T key)
{
    // first check if recursive call has to return
    if (!n) return n;
    
    if (key < n->key) {
        n->left = del(n->left, key);
    } else if (key > n->key) {
        n->right = del(n->right, key);
    } else {
        // matched the key, now have to delete the node
        // if either of the subtree not present then just return the other
        if (n->right == NULL) return n->left;
        if (n->left == NULL) return n->right;
        
        // in case both subtrees are present, replace the node
        // with the min of the right subtree, which is the successor
        class node<T> *t = n;
        n = min(n->right);
        n->right = derefMin(t->right);
        n->left = t->left;
        delete t;
    }
    
    n->size = 1 + (n->left ? n->left->size : 0) + (n->right ? n->right->size : 0) ;
    
    return n;
}


template <typename T>
void BT<T>::del(T key)
{
    root = del(root, key);
}

template <typename T>
bool BT<T>::search(T key)
{
    return search(root, key);
}

template <typename T>
bool BT<T>::search(class node<T> *n, T key)
{
    if (!n) return false;
    
    if ((n->key) < key) {
        return search(n->left, key);
    } else if ((n->key) < key) {
        return search(n->right, key);
    } else if (n->key == key){
        return true;
    }
    
    return false;
}

template <typename T>
int BT<T>::rank(class node<T> *n, T key)
{
    //cout << "rank called for : " << key << " node : " << (n ? n->key : 0) << endl;
    if (n == NULL) return 0;
    
    if (key < n->key) {
        return rank(n->left, key);
    } else if (key > n->key) {
        return 1 + (n->left ? n->left->size : 0) + rank(n->right, key);
    } else {
        return (n->left ? n->left->size : 0);
    }
}

template <typename T>
int BT<T>::rank(T key)
{
    return rank(root, key);
}

template <typename T>
class node<T> *BT<T>::floor(class node<T> *n, T key)
{
    if (n == NULL) return NULL;
    
    if (key == n->key) return n;
    if (key < n->key) return  floor(n->left, key);
    
    class node<T> *x = floor(n->right, key);
    if (x == NULL) return n;
    else return x;
}

template <typename T>
class node<T> *BT<T>::floor(T key)
{
    return floor(root, key);
}

template <typename T>
int BT<T>::maxDepth(class node<T> *node)
{
    if (node==NULL) {
        return(0);
    } else {
        // compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        
        // use the larger one
        if (lDepth > rDepth) {
            return(lDepth + 1);
        } else {
            return(rDepth + 1);
        }
    }
}

template <typename T>
int BT<T>::maxDepth()
{
    return maxDepth(root);
}

template <typename T>
void BT<T>::inorder(class node<T> *n)
{
    if (!n) return;
    inorder(n->left);
    cout << n->visit() << " , ";
    inorder(n->right);
}

template <typename T>
void BT<T>::preorder(class node<T> *n)
{
    if (!n) return;
    cout << n->visit() << " , ";
    preorder(n->left);
    preorder(n->right);
}

template <typename T>
void BT<T>::postorder(class node<T> *n)
{
    if (!n) return;
    postorder(n->left);
    postorder(n->right);
    cout << n->visit() << " , ";
}


template <typename T>
void BT<T>::inorder()
{
    cout << "Inorder : ";
    
    if (!root) {
        cout << "empty" << endl;
    }
    
    cout << "Elements : \n";
    inorder(root);
    cout << "\n";
}

template <typename T>
void BT<T>::preorder()
{
    cout << "Preorder : ";
    
    if (!root) {
        cout << "empty" << endl;
    }
    
    cout << "Elements : \n";
    preorder(root);
    cout << "\n";
}

template <typename T>
void BT<T>::postorder()
{
    cout << "Postorder : ";
    
    if (!root) {
        cout << "empty" << endl;
    }
    
    cout << "Elements : \n";
    postorder(root);
    cout << "\n";
}

template <typename T>
void BT<T>::mirror(class node<T> *n)
{
    if (!n) return;
    
    mirror(n->left);
    mirror(n->right);
    
    class node<T> *x = n->left;
    n->left = n->right;
    n->right = x;
}

template <typename T>
void BT<T>::mirror()
{
    mirror(root);
}

template <typename T>
void BT<T>::doubleT(class node<T> *n)
{
    if (!n) return;
    
    doubleT(n->left);
    doubleT(n->right);
    
    class node<T> *x = new node<T>(n->key);
    class node<T> *tmp = n->left;
    n->left = x;
    x->left = tmp;
    
}

template <typename T>
void BT<T>::doubleT()
{
    doubleT(root);
}


void testbtP()
{
    std::vector<int> i = {6, 3, 2, 5, 4, 8, 9};
    class BT<int> b(i);
    
    b.inorder();
    b.preorder();
    b.postorder();
    
    cout << ((b.search(6)) ? "found 6\n" : "no 6\n");
    cout << ((b.search(16)) ? "found 16\n" : "no 16\n");
    
    cout << "rank of 6 : " << b.rank(6) << endl;
    cout << "rank of 9 : " << b.rank(9) << endl;
    cout << "rank of 10 : " << b.rank(10) << endl;
    
    int f = 5;
    class node<int> *x = b.floor(f);
    cout << "floor of " << f << ": " << (x ? x->visit() : string("NULL")) << endl;
    
    cout << "maxdepth : " << b.maxDepth() <<endl;
    
    cout << "mirroring :\n";
    b.mirror();
    b.inorder();
    cout << "\n";
    
    cout << "mirroring again:\n";
    b.mirror();
    b.inorder();
    cout << "\n";
    
    //cout << "doubling :\n";
    //b.doubleT();
    //b.inorder();
    //cout << "\n";
    
    
    b.del(3);
    b.inorder();
    
    b.del(9);
    b.inorder();
    
    b.deleteMin();
    b.inorder();
    
}