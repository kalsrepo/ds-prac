//
//  minpq.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/14/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef minpq_hpp
#define minpq_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

template <typename T>
class minpq {
public:
    minpq (int size);
    
    void insert (int key, int value);
    int delMin ();
    bool contains (int key);
    std::vector<int> getlist();
};


#endif /* minpq_hpp */
