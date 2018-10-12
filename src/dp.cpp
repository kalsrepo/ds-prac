//
//  dp.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/20/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "dp.hpp"


using namespace std;

int count (int s[], int m, int n)
{
    if (n == 0) return 1; // one solution for no coin
    
    if (n < 0) return 0;  // no solution for negative value
    
    if (m <= 0 && n >= 1) return 0; // if no coin then no solution
    
    return count (s, m - 1, n) + count (s, m, n - s[m-1]);
}

int countSteps (int n, int *memo)
{
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        memo[n] = 1;
        return 1;
    } else if (memo[n] > -1 ){
        return memo[n];
    } else {
        memo[n] = countSteps(n-1, memo) + countSteps(n-2, memo) + countSteps(n-3, memo);
        return memo[n];
    }
}

int countSteps (int n)
{
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    }  else {
        return countSteps(n-1) + countSteps(n-2) + countSteps(n-3);
    }
}

int rMul (int a, int b)
{
    if (b == 0) return 0;
    if (b == 1) return a;
    int s = b / 2;
    int r = b % 2;
    int as = a << s;
    if (r) {
        return a + rMul(as, --r);
    } else {
        return as;
    }
}

void TowerOfHanoi (int n, int src, int dst, int aux)
{
    if (n == 0) return;
    
    TowerOfHanoi(n-1, src, aux, dst);
    
    cout << "move : " << n << " from : " << src << " : to : " << dst << endl;
    
    TowerOfHanoi(n-1, aux, dst, src);
}

#include <set>

bool findPath (int r, int c, std::set<std::pair<int, int>> &path,
               std::set<std::pair<int, int>> &blocked)
{
    /* check if we are at falling off the matrix */
    if ((r < 1) || (c < 1)) {
        return false;
    }
    
    /* check if this block is in blocked group */
    std::set<std::pair<int, int>>::iterator it = blocked.find(std::pair<int, int>(r, c));
    if (it != blocked.end()) {
        return false;
    }
    
    std::set<std::pair<int, int>>::iterator itp = path.find(std::pair<int, int>(r, c));
    if (itp != path.end()) {
        cout << "comint to : " << (*it).first << " " << (*it).second << "again\n";
        return true;
    }
    
    bool isAtOrigin = ((r == 1) && (c == 1));
    
    if (isAtOrigin || findPath(r - 1, c, path, blocked) || findPath(r, c - 1, path, blocked)) {
        path.insert(std::pair<int, int>(r, c));
        return true;
    }
    
    return false;
}

void robotGrid (int r, int c)
{
    std::set<std::pair<int, int>> path;
    std::set<std::pair<int, int>> blocked;
    
    blocked.insert(std::pair<int, int>(1, 2));
    blocked.insert(std::pair<int, int>(2, 2));
    //blocked.insert(std::pair<int, int>(3, 2));

    if (findPath(r, c, path, blocked)) {
        std::set<std::pair<int, int>>::iterator it = path.begin();
        while (it != path.end()) {
            cout << (*it).first << " " << (*it).second << "\n";
            it++;
        }
    } else {
        cout << "no path\n";
    }
}

std::string insertAt (string s, string c, int i)
{
    string first = s.substr(0, i);
    string last = s.substr(i);

    //cout << s << " " << first << " " << last << " " << i << '\n';
    
    string ret = first + c + last;
    
    //cout << ret << '\n';

    return ret;
}

std::vector<std::string> buildPermutations (std::string s)
{
    if (s.length() == 0) return std::vector<string>();
    
    //cout << "given : " << s << '\n';
    
    string first = s.substr(0, 1);
    string remainder = s.substr(1);

    //cout << "first : " << first << " remainder : " << remainder << '\n';

    std::vector<string> words = buildPermutations(remainder);
    
    std::vector<std::string> pers;
    
    if (words.size()) {
        for (string s : words) {
            for (int i = 0; i <= s.length(); i++) {
                string n = insertAt (s, first, i);
                pers.push_back(n);
            }
        }
    } else {
        pers.push_back(string(first));
    }
    
    return pers;
}



void testDp ()
{
    int d[] = {1, 2, 3};
    int coins = sizeof(d)/sizeof(int);
    
    cout << "no of solutions : " << count(d, coins, 9) << endl;
    
    int memo[10];
    for (int i = 0; i < 10; i++) {
        memo[i] = -1;
    }
    
    cout << "countSteps : " << countSteps(9, memo) << endl;
    cout << "countSteps : " << countSteps(9) << endl;
    
    cout << "mul : 8 * 2 : " << rMul(8, 3) << endl;
    
    TowerOfHanoi(3, 1, 3, 2);
    
    robotGrid(4, 4);
    
    std::vector<std::string> p = buildPermutations(string("abcde"));
    
    cout << '\n';
    for (auto a : p) {
        cout << a << " ";
    }
    cout << '\n';

}
