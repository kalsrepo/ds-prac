//
//  maxsumparallel.cpp
//  practice-personal-laptop
//
//  Created by Kallol Banerjee on 11/3/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "maxsumparallel.hpp"
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 
 Algorithm to compute max subsequence sum of an array in multi threaded way :
 
 Data is processed in chunks based on how many no of threads need to be spawned.
 
 Every thread calcuates 4 sums on the array segment:
 
 maxSum = max subsequence sum for that array
 lSum = max subsequence sum from the left including the left most array element
 rSum = max subsequence sum from the right including the right most array element
 sum  = total sum of all the array elements
 
 Once all the sums on all segments are are calculated then segment sums are merged to
 decide the max sequence sum.
 
 Every merge operation generates 4 sums as previous (maxSum, lSum, rSum, sum):
 
 lSum Merged = ((this.sum + other.lSum) > lSum) ? (sum of this + other.lSum) : lSum;
 rSum Merged = ((other.sum + rSum) > other.rSum) ? (other.sum + rSum) : other.rSum;
 over all sum = (this.sum + other.sum)
 
 max sum of the merged bigger segment would be the biggest of the following 6 entities:
 
 this.maxSum
 other.maxSum
 overall rSum
 overall lSum
 overall sum
 (this.rSum + other.lSum)
 
 */

struct SegmentSum {
    double maxSum = 0;
    double lSum = 0;
    double rSum = 0;
    double sum = 0;
    
    SegmentSum & mergeSegmentSum (struct SegmentSum &other)
    {
        // We need to consider between 6 sums
        double nums[6];
        
        // max sum for this
        nums[0] = this->maxSum;
        
        // max sum from other
        nums[1] = other.maxSum;
        
        // sum of elements inbetween
        nums[2] = this->rSum + other.lSum;
        
        // right sum of the overall elements
        rSum = nums[3] = ((other.sum + rSum) > other.rSum) ? (other.sum + rSum) : other.rSum;
        
        // left sum of the overall elements
        lSum = nums[4] = ((this->sum + other.lSum) > lSum) ? (sum + other.lSum) : lSum;
        
        // total sum of all elements
        sum = nums[5] = this->sum + other.sum;
        
        // Now find the max of all
        maxSum = 0;
        for (int i = 0; i < 6; i++) {
            if (nums[i] > maxSum) {
                maxSum = nums[i];
            }
        }
        return *this;
    }
    
    string toString()
    {
        string s = " [ " + to_string((int)maxSum) + " " + to_string((int)lSum) + " " +
                           to_string((int)rSum) + " " + to_string((int)sum) + " ] ";
        
        return s;
    }
};

struct ThreadArg {
    SegmentSum& sum;
    std::vector<int> &data;
    size_t sIndex;
    size_t eIndex;
    
    ThreadArg(SegmentSum& _sum, std::vector<int> &_data,
              size_t _sIndex, size_t _eIndex) :
          sum(_sum), data(_data), sIndex(_sIndex), eIndex(_eIndex) { }
};

void doSegmentSum (ThreadArg &targ)
{
    double &maxSum = targ.sum.maxSum = 0;
    double &lSum = targ.sum.lSum = targ.data[targ.sIndex];
    double &rSum = targ.sum.rSum = targ.data[targ.eIndex - 1];
    double &sum = targ.sum.sum = 0;
    double tmpSum = 0;
    
    for (size_t i = targ.sIndex; i < targ.eIndex; i++) {
        // Keep maintaining the sum
        sum += targ.data[i];
        
        if (lSum < sum) {
            lSum = sum;
        }
        
        // Calulate the running max sum
        // If it ever falls below 0 update
        tmpSum += targ.data[i];
        if (tmpSum < 0) {
            tmpSum = 0;
        }
        
        // update maxSum
        if (maxSum < tmpSum) {
            maxSum = tmpSum;
        }
    }

    tmpSum = 0;
    for (size_t i = targ.eIndex - 1; i >= targ.eIndex; --i) {
        // Keep maintaining the sum
        tmpSum += targ.data[i];
        
        // Calculate rSum
        if (rSum < tmpSum) {
            rSum = tmpSum;
        }
    }
    
    
    string s = "thread : " + to_string(targ.sIndex) + " " +
                             to_string(targ.eIndex) + " " +
                             targ.sum.toString() + "\n";
    
    std::cout << s;
    
}

void tJoin(std::thread& t)
{
    t.join();
}

double calculateMaxSumParallel (std::vector<int> &data, int numThreads)
{
    // create SegmentSum array
    size_t len = data.size();
    size_t chunkSize = (len / numThreads) ? (len / numThreads) : len;  // TODO: should not spawn more than numThreads
    
    // threads vector keep track of how many threads we are spawning
    std::vector<std::thread> threads;
    
    // vector of segSums to accumulate data from all thread runs
    std::vector<SegmentSum *> segSums;

    // call numThreads
    size_t start = 0, end;
    
    int threadsToBeScheduled = numThreads;
    
    do {
        /* calculate the end index based on chunks or num of threads */
        if ((len < 2 * chunkSize) || (threadsToBeScheduled == 1)) {
            end = start + len;
            len = 0;
        } else {
            end = start + chunkSize;
            len -= chunkSize;
        }
        
        // Create the thread args
        SegmentSum *s = new SegmentSum();
        segSums.push_back(s);
        ThreadArg *targ = new ThreadArg(*s, data, start, end);
        std::thread t(doSegmentSum, std::ref(*targ));
        threads.push_back(std::move(t));
        start += chunkSize;
        --threadsToBeScheduled;
        
    } while (len || threadsToBeScheduled);
    
    
    // Wait for all threads to finish
    std::for_each(threads.begin(),threads.end(), tJoin);
    
    // merge the rest of the data with the first element
    size_t segSumSize = segSums.size();
    if (segSumSize > 1) {
        for (int i = 1; i < segSumSize; i++) {
            (*segSums[0]).mergeSegmentSum(*segSums[i]);
        }
    }
    
    // return the max sum
    return (*segSums[0]).maxSum;
}

void testMaxSum ()
{
    //std::vector<int> v = {10, 20, -40, 100, 4, 50, -30, -72, 5};
    std::vector<int> v = {5, -2, 3};
#if 0
    std::vector<int> v;
    v.push_back(1000000);
    for (int i = 0; i < 1000000; i++) {
        v.push_back(-1);
    }
    v.push_back(1000000);
#endif
    std::cout << (long long)calculateMaxSumParallel(v, 1) << '\n';
}


