//
//  sort.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/20/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "sort.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <unistd.h>

using namespace std;

void merge (int a[], int aux[], int lo, int mid, int hi)
{
    for (int i = lo; i <= hi; i++) {
        aux[i] = a[i];
    }
    
    //cout << "merge : " << "lo : " << lo << " mid : " << mid << " hi : " << hi << endl;

    int i = lo;
    int j = mid + 1;
    
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            a[k] = aux[j++];
        } else if (j > hi) {
            a[k] = aux[i++];
        } else {
            if (aux[j] < aux[i]) {
                a[k] = aux[j++];
            } else {
                a[k] = aux[i++];
            }
        }
        
    }
}

void mergesort (int a[], int aux[], int lo, int hi)
{
    if (hi <= lo) return;
    //cout << "lo : " << lo << " hi : " << hi << endl;

    int mid = lo + (hi - lo)/2;
    
    mergesort(a, aux, lo, mid);
    mergesort(a, aux, mid + 1, hi);
    
    merge(a, aux, lo, mid, hi);
}

void exch (int a[], int i, int j)
{
    //cout << "exch : " << i << " " << j << endl;
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void randomShuffle (int a[], int len)
{
    sleep(1);
    /* initialize random seed: */
    srand((unsigned int)time(NULL));
    
    for (int i = 1; i < len; i++) {
        int j = rand() % i;
        exch(a, i, j);
    }
}

void bottomUpMerge (int a[], int aux[], int N)
{
    for (int sz = 1; sz < N; sz = sz+sz) {
        cout << "sz : " << sz << endl;
        for (int lo = 0; lo < N - sz; lo += (sz+sz)) {
            cout << "    lo : " << lo << " mid : " << lo + sz - 1 << " hi : " << min(lo + sz + sz -1, N -1) << endl;
            merge(a, aux, lo, lo + sz - 1, min(lo + sz + sz - 1, N -1));
        }
    }
}

void selectionSort (int a[], int len)
{
    for (int i = 0; i < len; i++) {
        int min = i;
        
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        exch(a, i, min);
    }
}

void insertionSort (int a[], int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j-1]) {
                exch(a, j, j -1);
            } else {
                break;
            }
        }
    }
}

int partition (int a[], int lo, int hi)
{
    int i = lo, j = hi + 1;
    
    while (true) {
        // move on till the element on the left < partition element
        while (a[++i] < a[lo]) {
            if (i == hi) break;
        }
        
        // move on till the element on the right > partition element
        while (a[lo] < a[--j]) {
            if (j == lo) break;
        }
        
        // stop if the pointers have crossed
        if (i >= j) break;
        
        exch(a, i, j);
    }
    
    // exchange with the partition element
    exch(a, j, lo);
    
    /*
    cout << "array : lo : " << lo << " hi : " << hi << " : " << " p : " << j << "\n";
    for (int i = 0; i < 6; i++) {
        cout << a[i] << " ";
    }
    cout << "\n"; */

    return j;
}

void quickSortInternal (int a[], int lo, int hi)
{
    if (hi <= lo) return;
    
    int j = partition(a, lo, hi);
    
    //cout << "partion : " << j << endl;
    
    quickSortInternal(a, lo, j-1);
    quickSortInternal(a, j+1, hi);
}

void quickSort (int a[], int len)
{
    //randomShuffle(a, len);
    
    quickSortInternal(a, 0, len-1);
}

#include <stack>
#include <deque>
#include <string>

void printStack (std::string str, std::stack<int> &s)
{
    std::stack<int> mystack1 = s;
    
    cout << str << " : ";
    while (!mystack1.empty()) {
        cout << mystack1.top() << " ";
        mystack1.pop();
    }
    cout << "\n";
    
}

void sortStack (std::stack<int> &s)
{
    std::stack<int> r;
    
    printStack(std::string("starting s"), s);

    while (!s.empty()) {
        printStack(std::string(" start s"), s);
        int tmp = s.top();
        s.pop();
        while (!r.empty() && r.top() > tmp) {
            s.push(r.top());
            r.pop();
        }
        r.push(tmp);
        printStack(std::string(" end r"), r);
    }
    
    while (!r.empty()) {
        s.push(r.top());
        r.pop();
    }
    
    printStack(std::string("ending s"), s);
}


void testSort1()
{
    std::deque<int> myd = {20, 10, 50, 23, 3, 7, 1, 200};
    
    std::stack<int> mystack(myd);
    

    sortStack(mystack);
    

}

void testSort ()
{
    int a[] = {20, 4, 12, 28, 2, 90, 50, 32 };
    int size = sizeof(a)/sizeof(int);
    int aux[size];

/*
    randomShuffle(a, size);
    
    cout << "suffled sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    cout << "selection sort \n";
    
    selectionSort(a, size);

    cout << "after sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    randomShuffle(a, size);
    
    cout << "suffled sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    cout << "insertion sort \n";

    insertionSort(a, size);
    
    cout << "after sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    
    randomShuffle(a, size);
    
    cout << "suffled sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    cout << "merge sort \n";

    mergesort(a, aux, 0, 5);
    
    cout << "after sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    */
    
    randomShuffle(a, size);
    
    cout << "suffled sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    cout << "bottomup merge sort \n";

    bottomUpMerge(a, aux, size);
    
    cout << "after sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";

    /*
    
    randomShuffle(a, size);
    
    cout << "suffled sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    
    cout << "quickSort sort \n";
    
    quickSort(a, size);
    
    cout << "after sort array : ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
 */

}
