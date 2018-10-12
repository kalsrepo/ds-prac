//
//  mm.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/13/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "mm.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

mm::mm (int size) : _size(size)
{
    void * block = calloc(1, size);
    
    int chunkSize = sizeof(struct element);
    int overhead = sizeof(struct base);
    
    cout << "chunkSize : " << chunkSize << " overhead : " << overhead << endl;
    
    int noBlocks = (_size - overhead) / chunkSize;
    
    head = (struct base *)block;
    head->total = head->no_free = noBlocks;

    head->n = (struct element *)((char *)block + overhead);
    
    char *start = ((char *)block + overhead);
    head->lower = start;
    head->upper = start + (noBlocks * chunkSize);
    
    for (int i = 0; i < noBlocks; i++) {
        struct element *e = (struct element *)start;
        e->next = (struct element *)(start + chunkSize);
        start += chunkSize;
    }
}

void * mm::allocMem ()
{
    if (!(head->no_free)) {
        return NULL;
    }
    
    struct element *e = head->n;
    head->n = e->next;
    head->no_free -= 1;
    
    return e;
    
}

void mm::freeMem(void *mem)
{
    char *check = (char *) mem;
    if (check < head->lower || check > head->upper) {
        cout << "memory out of range\n";
        return;
    }
    
    struct element *e = (struct element *)mem;
    
    e->next = head->n;
    head->n = e;
    head->no_free += 1;
}

int mm::totalBlocks()
{
    return head->total;
}

int mm::noFreeBlocks()
{
    return head->no_free;
}

void testmm ()
{
    class mm *m = new mm(100);
    
    cout << m->totalBlocks() << endl;
    
    char * x = (char *) m->allocMem();
    
    cout << m->noFreeBlocks() << endl;

    m->freeMem(x);
    
    char *a = (char *)malloc(8);
    
    m->freeMem(a);
    
    cout << m->noFreeBlocks() << endl;
}