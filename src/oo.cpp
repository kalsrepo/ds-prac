//
//  oo.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/16/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "oo.hpp"

void testOo ()
{
    MyClass m(1);
    
    m(10);
    
    MyClass m1(2);
    
    std::cout << (m1 < m) << "\n";
    std::cout << (m < m1) << "\n";

    std::cout << (m1 > m) << "\n";

}