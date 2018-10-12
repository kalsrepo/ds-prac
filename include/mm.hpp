//
//  mm.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/13/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef mm_hpp
#define mm_hpp

#include <stdio.h>




class mm {
    void *block;
    int _size;

    struct element {
        struct element *next;
    };

    struct base {
        int total;
        int no_free;
        char *lower;
        char *upper;
        struct element *n;
    } *head;
    
public:
    mm (int size);
    void * allocMem();
    void freeMem(void *mem);
    
    int totalBlocks();
    int noFreeBlocks ();
};


void testmm();

#endif /* mm_hpp */
