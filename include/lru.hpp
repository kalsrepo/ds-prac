//
//  lru.hpp
//  datastructures
//
//  Created by Kallol Banerjee on 9/14/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#ifndef lru_hpp
#define lru_hpp

#include <stdio.h>

#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

class LRUCache{
private:
    int _capacity;
    std::list<int> _lru;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> _cache;
    
    void use (std::unordered_map<int, std::pair<int, std::list<int>::iterator>>::iterator& it) {
        std::list<int>::iterator lit = it->second.second;
        _lru.erase(lit);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
    
public:
    LRUCache(int capacity) : _capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = _cache.find(key);
        
        if (it == _cache.end()) {
            return -1;
        }
        
        use(it);
        
        return it->second.first;
        
    }
    
    void set(int key, int value) {
        auto it = _cache.find(key);
        
        /* If the entry is in the cache is just update it */
        if (it != _cache.end()) {
            it->second.first = value;
            use(it);
            return;
        }
        
        /* If a new entry and cache is at capacity get rid of lru */
        if (_cache.size() == _capacity) {
            auto rit = _lru.rbegin();
            int km = *rit;
            _lru.pop_back();

            auto cit = _cache.find(km);
            _cache.erase(cit);
        }
        
        /* now set the new entry */
        _lru.push_front(key);
        _cache[key] = std::make_pair(value, _lru.begin());
        return;
    }
    
    void print() {
        std::cout << "cache elements : \n";
        for (auto it = _cache.begin(); it != _cache.end(); it++) {
            std::cout << it->first << " : " << it->second.first << std::endl;
        }
        
        std::cout << "LRU : \n";
        for (auto it = _lru.begin(); it != _lru.end(); it++) {
            std::cout << *it << " : ";
        }
        std::cout << "\n";

    }
};

void test_cache();

#endif /* lru_hpp */
