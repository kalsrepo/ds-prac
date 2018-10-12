//
//  main.cpp
//  C++ Data structures
//
//  Created by Kallol Banerjee on 3/14/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include <iostream>

#include "testgraph.hpp"
#include "testbt.hpp"
#include "ArraysStrings.hpp"
#include "linkedlist.hpp"
#include "dp.hpp"
#include "sort.hpp"
#include "pq.hpp"
#include "gencpp.hpp"
#include "mm.hpp"
#include "lru.hpp"
#include "oo.hpp"
#include "trie.hpp" 
#include "circular-queue.hpp"
#include "maxsumparallel.hpp"

#include <map>

using namespace std;


void print(int ar_size, vector<int>& ar) {
    for (int i = 0; i < ar_size; i++) {
        cout << ar[i] << " ";
    }
    cout << "\n";
}

void insertionSort(int ar_size, vector<int>& ar) {
    for (int i = 1; i < ar_size; i++) {
        for (int j = i; j >= 0; j--) {
            if (ar[j] < ar[j-1]) {
                int temp = ar[j - 1];
                ar[j -1] = ar[j];
                ar[j] = temp;
            } else {
                break;
            }
            print(ar_size, ar);
        }
    }
}

void testRange ()
{
    int start = 0, end, len = 19, chunkSize = 4;
    end = std::min((start + chunkSize), len);
    for (start = 0; start < len; start += chunkSize, end = min((start + chunkSize), len)) {
        cout << start << " , " << end << '\n';
    }
}

void calulateMaxSum (std::vector<int> &v)
{
    double maxSum = v[0];
    double lSum = v[0];
    double rSum = v[v.size() - 1];
    double sum = 0;
    double tmpSum = 0;
    
    for (int i = 0; i < v.size(); i++) {
        // Keep maintaining the sum
        sum += v[i];
        
        if (lSum < sum) {
            lSum = sum;
        }
        
        // Calulate the running max sum
        // If it ever falls below 0 update
        tmpSum += v[i];
        if (tmpSum < 0) {
            tmpSum = 0;
        }
        
        // update maxSum
        if (maxSum < tmpSum) {
            maxSum = tmpSum;
        }
    }
    
    tmpSum = 0;
    for (int i = (int)(v.size() - 1); i >= 0; --i) {
        // Keep maintaining the sum
        tmpSum += v[i];
        
        if (rSum < tmpSum) {
            rSum = tmpSum;
        }
    }
    
    cout << "sum : " << sum << " lSum : " << lSum << " rSum : " << rSum << " maxSum : " << maxSum << '\n';
}


int main(int argc, const char * argv[]) {
    //dfs_test();
    //bfs_test();
    //testbt();
    //testbtP();

    //testArrayString();
    //testList();
    //testDp();
    
    //testSort();
    //testSort1();
    
    testPQ();
    
    //testGenCpp();
    
    //testSubStringGen();
    
    //testmm();
    
    //findIceCreams();
    
    //test_cache();
    
    //testOo();
    
    //testTrie();
    
    //testList1();
    
    //testCirQ();
    
    // testRange();
    
    /*
     int x1[] = {10, 20, -40, 100, 4, 50, -30, -72, 5};
     
     int x2[] = {10, 20, -40};
     
     int x3[] = {-100, -20, -40};
 
     int x4[] = {5, -2, 3};
     */

    //std::vector<int> v = {10, 20, -40, 100, 4, 50, -30, -72, 5};

    //calulateMaxSum(v);

    //testMaxSum();

    return 0;
}
