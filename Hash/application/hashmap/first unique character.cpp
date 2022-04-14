#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
using namespace std;

/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

--------- example ---------
Input: s = "leetcode"
Output: 0

*/



class Solution {
public:

    int firstUniqChar(string s) {
        set<int> S;
        map<char, int> M;
        for(int i = 0; i < s.size(); ++i){
            if( M.find(s[i]) == M.end() ){
                M[s[i]] = i;
                S.insert(i);
            }
            else{
                // M.erase(s[i]); // character could repeat more than 2 times, so don't erase the repeat one!!!
                S.erase(M[s[i]]);
            }
        }
        return !S.empty() ? *(S.begin()):-1;
    }
};
