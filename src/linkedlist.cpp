//
//  linkedlist.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/5/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "linkedlist.hpp"
#include <vector>
#include <memory.h>
#include <stdlib.h>
#include <assert.h>
#include <list>
#include <stack>
#include <iostream>

using namespace std;

struct node {
    struct node *next;
    int i;
};


struct node * buildList(std::vector<int> v)
{
    struct node *head = NULL;
    struct node *tail = head;
    
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        //cout << *it << " ";

        struct node *n = (struct node *)calloc(1, sizeof(struct node));
        n->i = *it;
        if (!head) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    //cout << "\n";

    return head;
}

void printList (std::string name, struct node *n)
{
    cout << "printing list (" << name << ") : \n";
    for (struct node *l = n; l; l = l->next) {
        cout << l->i << " ";
    }
    cout << "\n";
}

struct node * reverse (struct node *n, struct node **head, struct node **next)
{
    if (!n) return NULL;
    
    struct node *h = reverse(n->next, head, next);
    if (h == NULL) {
        *head = n;
        *next = *head;
    } else {
        (*next)->next = n;
        *next = n;
        (*next)->next = NULL;
    }
    return *next;
}

void addNodeToHead (struct node** head, int val)
{
    struct node *n = (struct node *)calloc(1, sizeof(struct node));
    n->i = val;
    
    n->next = *head;
    *head = n;
}

struct node * removeFromHead (struct node **head)
{
    if (!head || !(*head)) return NULL;
    
    struct node *r = (*head);
    
    (*head) = (*head)->next;
    free (r);
    
    return (*head);
}

void removeDuplicates (struct node **h)
{
    if (!h || !(*h) || !((*h)->next)) return;
    
    struct node *c, *n;
    
    c = *h;
    n = (*h)->next;

    while (n) {
        if (c->i == n->i) {
            c->next = removeFromHead(&n);
            n = c->next;
        } else {
            c = n;
            n = n->next;
        }
    }
    
    return;
}


int countList (struct node *head)
{
    if (!head) return 0;
    
    struct node *f, *s;
    int count = 1;
    
    f = s = head;
    
    while (1) {
        if (!(f->next)) return (count * 2) - 1;
        if (!(f->next->next)) return (count * 2);
        count++;
        s = s->next;
        f = f->next->next;
    }
}


struct node * moveNode (struct node **from)
{
    assert(from || (*from));
    
    struct node *n = (*from);
    (*from) = (*from)->next;
    
    return n;
}


struct node *shuffleMerge (struct node *a, struct node *b)
{
    bool first = true;
    struct node dummy;
    struct node *t = &dummy;
    dummy.next = NULL;
    
    while (a || b) {
        if (!a) {
            t->next = b;
            break;
        }
        
        if (!b) {
            t->next = a;
            break;
        }
        
        if (first) {
            t->next = moveNode(&a);
            first = false;
        } else {
            t->next = moveNode(&b);
            first = true;
        }
        
        t = t->next;
    }
    
    return dummy.next;
}

void RecursiveReverse(struct node** headRef) {
    struct node* first;
    struct node* rest;

    if (*headRef == NULL) {
        cout << "return headref null\n";
        return;
    }          // empty list base case

    first = *headRef;    // suppose first = {1, 2, 3}￼
    rest = first->next;  // rest = {2, 3}

    if (rest == NULL) {
        cout << "return rest null\n";
        return; // empty rest base case
    }

    RecursiveReverse(&rest); // Recursively reverse the smaller {2, 3} case
                             // after: rest = {3, 2}
    first->next->next = first; // put the first elem on the end of the list
    first->next = NULL;        // (tricky step -- make a drawing)
    *headRef = rest;     // fix the head pointer
}

void testList()
{
    int myints[] = {1, 2, 3};
    
    std::vector<int> first (myints, myints + sizeof(myints) / sizeof(int) );
    
    struct node *head = buildList(first);
    
    printList(string("head"), head);
    
    RecursiveReverse(&head);
    
    printList(string("reverse head"), head);
}

static void checkListPalindrome ()
{
    int myints[] = {16,2, 1, 4, 2, 16};
    std::list<int> mylist (myints, myints + sizeof(myints) / sizeof(int) );
    
    std::stack<int> mystack;
    
    std::list<int>::iterator it = mylist.begin();
    std::list<int>::iterator itFast = mylist.begin();
    
    //bool odd = false;
    /* populate stack */
    while (itFast != mylist.end()) {
        cout << *it << " " << *itFast << "\n";
        
        mystack.push(*it);
        it++;
        
        itFast++;
        if (itFast != mylist.end()) {
            itFast++;
        }
    }
    
    if (mystack.size() % 2) {
        mystack.pop();
    }
    
    /* check stack */
    while (it != mylist.end()) {
        if (*it != mystack.top()) {
            cout << "not palindrome\n";
            return;
        }
        mystack.pop();
        it++;
    }
    
    cout << "is palindrome\n";
}


void testList1 ()
{
    //int myints[] = {16,2,77,29};
    //int myints[] = {16, 16, 16, 20};
    int myints[] = {16,2,77,30, 30, 90, 4, 8};
    //int myints[] = {16};
    int myintsOther[] = {11, 71, 36};

    std::vector<int> first (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> second (myintsOther, myintsOther + sizeof(myintsOther) / sizeof(int) );
    
    struct node *head = buildList(first);
    struct node *headOther = buildList(second);

    printList(string("head"), head);
    printList(string("headOTher"), headOther);
    
    cout << "count head: " << countList(head) << endl;
    cout << "count headOther: " << countList(headOther) << endl;

    struct node *s = shuffleMerge(head, headOther);

    printList(string("shuffleMerged"), s);

    cout << "count merged: " << countList(s) << endl;

    cout << "After removing duplicates :\n";

    removeDuplicates(&head);

    printList(string("head"), head);
    
    cout << "count : " << countList(head) << endl;
    
    RecursiveReverse(&head);
    
    printList(string("reverse head"), head);
    
    struct node *nh = NULL;
    struct node *next = NULL;
    
    next = reverse(head, &nh, &next);
    printList(string("head reverse"), nh);
    
    checkListPalindrome();
}


