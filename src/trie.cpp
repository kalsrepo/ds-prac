//
//  trie.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/19/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "trie.hpp"

using namespace std;

Trie::Trie ()
{
    root = new node(-1);
    for (int i = 0; i < 26; i++) {
        root->n[i] = NULL;
    }
}

struct Trie::node* Trie::addInternal(struct node *n, std::string &key, int d, int value)
{
    cout << "key : " << key << " : " << d << " : " << (char)tolower(key[d - 1]) << "\n";
    
    if (n == NULL) {
        n = new node(-1);
        n->k = tolower(key[d - 1]);
    }
    
    if (d == (key.length())) {
        cout << "setting the value\n";
        n->_value = value;
    } else {
        if (n->n[tolower(key[d - 1]) - 'a']) {
            cout << "node exists\n";
        }
        n->n[tolower(key[d -1]) - 'a'] = addInternal(n->n[tolower(key[d - 1]) - 'a'],
                                                  key, d+1, value);
    }

    return n;
}

void Trie::add (std::string key, int value)
{
    root->n[tolower(key[0]) - 'a'] = addInternal(root->n[tolower(key[0]) - 'a'], key, 1, value);
}

int Trie::getInternal(struct node *n, std::string &key, int d)
{
    cout << "get : " << key << " : " << d << "\n";
    if (key.length() == d) {
        if (n->_value > 0) {
            return n->_value;
        } else {
            /* no match */
            return -1;
        }
    }
    
    /* Try to get the next child node to traverse */
    struct node *child = n->n[tolower(key[d-1]) - 'a'];
    
    if (child) {
        return getInternal(child, key, d+1);
    } else {
        return -1;
    }
}

int Trie::get(std::string &key)
{
    return getInternal(root->n[tolower(key[0]) - 'a'], key, 1);
}

struct Trie::node * Trie::delInternal (struct node *n, std::string &key, int d, bool &delParent)
{
    struct node * cur = n;
    
    /* If key length does not match to label */
    if (key.length() > d) {
        if (n->n[tolower(key[d -1]) - 'a'] == NULL) {
            /* Key not found */
            cout << "del : no key found\n";
            return NULL;
        } else {
            /* else traverse down */
            cout << "del : still entering " << d << "\n";
            n = delInternal(n->n[tolower(key[d -1]) - 'a'], key, d + 1, delParent);
        }
        
    }
    
    /* If key length match to label */
    if (key.length() == d) {
        if (n == NULL) {
            return NULL;
        }
        
        /* If there is at least one child we can not delete this
           node but just delete the value */
        bool ifChild = false;
        for (int i = 0; i < 26; i++) {
            if (n->n[i]) {
                ifChild = true;
                break;
            }
        }
        
        /* If no children then delete this node and then
           mark for parents to be checked for deletion */
        if (!ifChild) {
            cout << "no child so delete the key\n";
            free(n);
            delParent = true;
            return NULL;
        }
        
        /* If there at least one child found then just negate the value */
        cout << "child found so just change the key\n";

        n->_value = -1;
        return n;
    }
    
    /* check if we have to delete any parent node */
    if (delParent) {
        if (cur->_value < 0) {
            free(cur);
            return NULL;
        } else {
            delParent = false;
        }
    }
    
    cout << "returning : " << (char)(n->k) << " : " << d << "\n";
    return cur;
}


void Trie::del(std::string &key)
{
    bool delP = false;
    root->n[tolower(key[0]) - 'a'] = delInternal(root->n[tolower(key[0]) - 'a'], key, 1, delP);
}


void testTrie()
{
    Trie t = Trie();
    
    t.add(string("add"), 2);
    t.add(string("add"), 3);
    t.add(string("bad"), 4);
    t.add(string("border"), 5);
    t.add(string("borders"), 6);

    
    string s("add");
    cout << t.get(s) << "\n";

    s = string("bad");
    cout << t.get(s) << "\n";

    s = string("border");
    cout << t.get(s) << "\n";

    s = string("borders");
    cout << t.get(s) << "\n";

    t.add(string("borders"), 7);

    s = string("borders");
    cout << t.get(s) << "\n";
    
    s = string("border");
    t.del(s);
    cout << t.get(s) << "\n";

    s = string("borders");
    cout << t.get(s) << "\n";

}
