//
//  trie.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/19/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef trie_hpp
#define trie_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Trie {
    
    struct node {
        char k;
        struct node *n[26];
        int _value;

        node (int value): _value(value) {}
    };
    
    struct node *root;
    
    struct node * addInternal (struct node *n, std::string& key, int d, int value);
    int getInternal (struct node *n, std::string &key, int d);
    struct node * delInternal (struct node *n, std::string &key, int d, bool &delParent);

public:
    Trie ();
    
    void add (std::string key, int value);
    int get (std::string &key);
    void del (std::string &key);
};

void testTrie();

#endif /* trie_hpp */
