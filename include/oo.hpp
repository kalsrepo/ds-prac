//
//  oo.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/16/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef oo_hpp
#define oo_hpp

#include <stdio.h>
#include <iostream>

class MyClass {
    int _i;
public:

    MyClass (int i) : _i(i) {}
    void operator () (int i) const
    {
        std::cout << "this is s OO test " << i << "\n";
    }
    
    inline bool operator< (MyClass &other) const
    {
        return (_i < other._i);
    }
    inline bool operator> (MyClass &other) const
    {
        return (_i > other._i);
    }

};

void testOo();

#endif /* oo_hpp */
