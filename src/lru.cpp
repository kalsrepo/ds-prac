//
//  lru.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/14/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "lru.hpp"

void test_cache()
{
    LRUCache c(3);
    
    c.set(1, 2);
    c.set(2, 2);
    c.set(3, 10);
    c.get(1);
    c.print();
    c.set(4, 1);
    c.print();
    
}