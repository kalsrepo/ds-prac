//
//  ArraysStrings.cpp
//  datastructures
//
//  Created by Kallol Banerjee on 6/3/16.
//  Copyright © 2016 Kallol Banerjee. All rights reserved.
//

#include "ArraysStrings.hpp"

using namespace std;

bool UniqueString(std::string s)
{
    for (int i = 0; i < s.length(); i++) {
        for (int j=i+1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

bool UniqueStringUsingSort(std::string s)
{
    std::string c = s;
    
    std::sort(c.begin(), c.end());
    
    cout << "<" << s << " : sorted : " << c << "> ";
    
    for (int i = 0; i < c.length() - 1; i++) {
        if (c[i] == c[i+1]) {
            return false;
        }
    }
    
    return true;
}

bool StringIsPermutation (string a, string b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    return ((a.compare(b) == 0) ? true : false);
}

string Urlify (string input)
{
    size_t len = input.length();
    char *c = (char *)calloc(len + 1000, sizeof(char));
    
    cout << "input : " << input << " : len : " << len << endl;
    
    memmove(c, input.c_str(), input.length());
    
    cout << "c array : " << c << endl;
    
    
    char u[] = "%20";
    size_t ul = strlen(u);
    size_t uLen = ul - 1;
    
    cout << "ul : " << ul << endl;

    for (int i = 0; i < len; i++) {
        if (c[i] == ' ') {
            cout << i << " : " << len << endl;

            cout << "c array : detection : " << c << endl;

            memcpy(&c[i + ul], &c[i + 1], (len + i));
            cout << "c array : move : " << c << endl;

            memcpy(&c[i], u, ul);
            cout << "c array : replace : " << c << endl;

            i += uLen;
            len += uLen;
        }
    }
    
    string output(c);
    
    return output;
}

bool binarySearch(std::vector<int> &input, int ele, int start, int end)
{
    int mid = (end + start) / 2;
    
    cout << start << " : " << mid << " : " << end << endl;

    if (start > end) {
        return false;
    }
    
    if (input[mid] == ele) {
        cout << "found element at index : " << mid << endl;
        return true;
    } else if (input[mid] > ele) {
        return binarySearch(input, ele, start, mid -1 );
    } else if (input[mid] < ele) {
        return binarySearch(input, ele, mid + 1, end);
    }
    
    return true;
}

string CompressString (std::string s)
{
    string output;
    int count = 0;
    char c = s[0];
    
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        if (*it == c) {
            count++;
        } else {
            output = output + c + std::to_string(count);
            c = *it;
            count = 1;
        }
    }
    
    // for the last element
    output = output + c + to_string(count);
    
    if (output.length() > s.length()) {
        return s;
    } else {
        return output;
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    int size = (int)nums.size();
    vector<int> results;
    
    for (int i = 0; i < size; i++) {
        int toFind = target - nums[i];
        for (int j = i+1; j < size; j++) {
            if (nums[j] == toFind) {
                results.push_back(i);
                results.push_back(j);
            }
        }
    }
    
    return results;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *n)
{
    while (n) {
        cout << n->val << " ";
        n = n->next;
    }
    cout << "\n";
}


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    ListNode *tail = NULL, *head = NULL;
    int one = 0;
    int two = 0;
    int carry = 0;
    int n;
    
    while (l1 || l2 || carry) {
        if (l1 || l2) {
            one = (l1 ? l1->val : 0);
            two = (l2 ? l2->val : 0);
            
            n = (one + two + carry) % 10;
            carry = (one + two + carry) / 10;
            
            if (l1) { l1 = l1->next; }
            if (l2) { l2 = l2->next; }
        } else {
            n = carry;
            carry = 0;
        }
        
        ListNode *tmp = new ListNode(n);
        if (!head) {
            head = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
    }
    
    return head;
}

void TestaddTwoNumbers ()
{
    // [2,4,3]
    
    ListNode *head, *tail, *tmp;
    
    head = tail = new ListNode(2);
    tmp = new ListNode(4);
    tail->next = tmp;
    tail = tmp;
    tmp = new ListNode(3);
    tail->next = tmp;
    tail = tmp;
    
    printList(head);
    
    ListNode *first = head;
    
    // [5,6,8]

    head = tail = new ListNode(5);
    tmp = new ListNode(6);
    tail->next = tmp;
    tail = tmp;
    tmp = new ListNode(8);
    tail->next = tmp;
    tail = tmp;
    
    printList(head);
    
    ListNode *second = head;

    // add
    ListNode* res = addTwoNumbers(first, second);
    
    printList(res);

}


struct BiggestSum {
    int sidx;
    int eedx;
    int sum;
};

struct BiggestSum CalculateBiggestSum (int  a[], int size)
{
    struct BiggestSum biggest = {0 , 0, a[0]};
    struct BiggestSum tmp = {-1 , -1, 0};
    int s = 0;
    
    for (int i = 0; i < size; i++) {
        if (tmp.sidx < 0) {
            cout << "reset at idx : " << i << endl;
            tmp.sidx = tmp.eedx = i;
            tmp.sum = a[i];
            if (biggest.sum < tmp.sum) {
                cout << "storing : " << biggest.sum << ", " << biggest.sidx << " , " << biggest.eedx << endl;
                biggest = tmp;
            }
            continue;
        }
        
        s = tmp.sum + a[i];
        if (s < 0) {
            // special case for the -ve
            if (biggest.sum < a[i]) {
                biggest.sum = a[i];
                biggest.sidx = biggest.eedx = i;
            }
            tmp.sidx = -1;
            continue;
        }
        
        tmp.sum = s;
        tmp.eedx = i;
            
        cout << "update : " << tmp.sum << ", " << tmp.sidx << " , " << tmp.eedx << endl;

        
        if (biggest.sum < tmp.sum) {
            biggest = tmp;
            cout << "storing : " << biggest.sum << ", " << biggest.sidx << " , " << biggest.eedx << endl;
        }
    }
    
    return biggest;
}

string reverseSentence (const string &s)
{
    if (s.length() == 0) return NULL;
    
    string st = s;
    string rev;
    
    while (st.length()) {
        size_t a = st.find(" ");
        if (a == std::string::npos) {
            cout << st << endl;
            rev = st + " " + rev;
            break;
        }
        string x = st.substr(0, a);
        st = st.substr(a+1, st.length());
        cout << x << endl;
        if (rev.length()) {
            rev = x + " " + rev;
        } else {
            rev = x;
        }
    }
    
    return rev;
}

bool isPalindrome (string s, int start, int end)
{
    size_t len = end - start;
    if (len < 2) return true;
    
    int mid = (int) len/2;
    int i = 0;
    int j = (int)(len - 1);
    
    for (; i < mid; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    
    return true;
}

void toggle (unsigned int &bmap, int pos)
{
    unsigned int mask = 0;
    mask = 1 << pos;
    //cout << "start bmap : " << bmap << '\n';
    //cout << "mask : " << mask << " pos : " << pos << '\n';
    if ((bmap & mask) >= 1) {
        bmap &= (~mask);
    } else {
        bmap |= mask;
    }
    //cout << "end bmap : " << bmap << '\n';
}
            
bool isPalindromPermutation (string s1)
{
    unsigned int bitmap = 0;
    
    for (std::string::iterator it = s1.begin(); it != s1.end(); it++) {
        int pos = tolower(*it) - 'a';
        toggle(bitmap, pos);
    }
    
    if ((bitmap == 0) || ((bitmap & (bitmap - 1)) == 0)) {
        return true;
    }

    return false;
}
            
            
void testArrayString ()
{
    cout << string("abcd") << " result : " << UniqueString(string("abcd")) << endl;
    cout << string("abcda") << " result : " << UniqueString(string("abcda")) << endl;
    cout << string("abcd") << " result : " << UniqueStringUsingSort(string("abcd")) << endl;
    cout << string("abcda") << " result : " << UniqueStringUsingSort(string("abcda")) << endl;
    cout << string("wefghcda") << " result : " << UniqueStringUsingSort(string("wefghcda")) << endl;

    string a = string("abc");
    string b = string("bcab");
    cout << a << " : " << b << " : " << StringIsPermutation(a, b) << endl;
    
    string s = "This is a test string";
    cout << Urlify(s) << endl;
    
    vector<int>  x = { 10, 6, 3, 7, 9, 1, 2 };
    
    std::sort(x.begin(), x.end());
    
    cout << "\n";
    for (std::vector<int>::iterator it = x.begin(); it != x.end(); it++) {
        cout << " " << *it;
    }
    cout << "\n";

    cout << "element 11 : " << binarySearch(x, 11, 0, 6) << endl;
    cout << "element 7 : " << binarySearch(x, 7, 0, 6) << endl;
    
    
    cout << CompressString(string("aaaaabbbbbccccd")) << endl;
    cout << CompressString(string("abcd")) << endl;
    
    vector<int>  y = { 1, 3, 5, 7, 9, 10, 12 };

    vector<int> res = twoSum(y, 8);
    
    cout << "\n";
    for (std::vector<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
    
    TestaddTwoNumbers();
    /*
    int x1[] = {10, 20, -40, 100, 4, 50, -30, -72, 5};
    
    int x2[] = {10, 20, -40};

    int x3[] = {-100, -20, -40};
*/
    int x4[] = {5, -2, 3};

    int size = sizeof(x4)/sizeof(int);
    
    struct BiggestSum b1 = CalculateBiggestSum(x4, size);
    
    cout << "sidx : " << b1.sidx << " eidx : " << b1.eedx << " sum : " << b1.sum << endl;
    
    cout << reverseSentence(string("this is my string")) << endl;
    
    cout <<  isPalindrome (string("a"), 0, 1) << endl;
    cout <<  isPalindrome (string("ab"), 0, 2) << endl;
    cout <<  isPalindrome (string("aba"), 0, 3) << endl;
    cout <<  isPalindrome (string("abaaba"), 3, 6) << endl;
    
    cout << "isPalindromPermutation : " << isPalindromPermutation(string("aabbdffder")) << '\n';
 }
    
void fillSubStringSet (string &s, std::map<char, std::set<string>> &set)
{
    std::map<char, std::set<string>>::iterator it;
    std::set<string> v;
    
    for (int i = 0; i < s.length(); i++) {
        it = set.find(s[i]);
        
        if (it != set.end()) {
            v = set[s[i]];
        }
        
        for (int j = 1; j <= s.length() - i; j++) {
            cout << i << " , " << j << " : " << s.substr(i, j) << endl;
            v.insert(s.substr(i, j));
        }
        set[s[i]] = v;
        v = std::set<string>();
    }
                
}

      
int calculateMutations1 (string s) {
    string r;
    std::map<char, std::set<string>> setSubStr;
    
    size_t len = s.length();
    size_t index = 0;
    int cost = 0;
    
    while (index < len) {
        cout << "index : " << index << endl;
        if (!setSubStr.empty()) {
            // check if there is something to be matched
            char f = s[index];
            
            // check for substring for the next char in the string
            std::map<char, std::set<string>>::iterator it = setSubStr.find(f);
            if (it != setSubStr.end()) {
                std::set<string> v = setSubStr[f];
                if (!v.empty()) {
                    int matchLen = 0;
                    for (std::set<string>::iterator its = v.begin(); its != v.end(); its++) {
                        size_t t = s.find(*its, index);
                        if (t > matchLen) {
                            matchLen = (int)t;
                        }
                    }
                    if (matchLen > 0) {
                        index += matchLen;
                        r = s.substr(0, index+1);
                        continue;
                    }
                }
            }
        }
        
        // update the target string with the next char
        // account for the cost
        cost++;
        r = s.substr(0, index + 1);
        index++;

        cout << r << endl;
        // update substring
        fillSubStringSet(r, setSubStr);
    }
    return cost;
}

int calculateMutations (string s) {
    size_t len = s.length();
    size_t index = 0;
    int cost = 0;
    std::map<char, int> letters;
    std::map<char, int>::iterator it;
    
    while (index < len) {
        cout << "index : " << index << endl;
        it = letters.find(s[index]);
        if (it == letters.end()) {
            cost++;
        }
        letters[s[index]] = 1;
        index++;
    }
    return cost;
}
            
void testSubStringGen ()
{
    string s("abcd");
    /*
    std::map<char, std::set<string>> set;
    
    fillSubStringSet(s, set);
    
    string s1("abcdc");
    
    fillSubStringSet(s1, set);
    
    for (std::map<char, std::set<string>>::iterator it = set.begin(); it != set.end(); it++) {
        cout << it->first << " : ";
        std::set<string> ss = it->second;
        for (std::set<string>::iterator its = ss.begin(); its != ss.end(); its++) {
            cout << *its << " ";
        }
        cout << "\n";
    }
    */
    cout << calculateMutations(s) << endl;
}


            

            
