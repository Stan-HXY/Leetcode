#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
--------- abc

Input: s = "pwwkew"
Output: 3
--------- wke
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1){
            return s.size();
        }
        unordered_map<char, int> M;
        int res = 0; int size = s.size();
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(M.find(s[i]) != M.end()){
                j = max(M[s[i]] + 1, j); // 有可能重复的在前面
            }
            M[s[i]] = i;
            res = max(res, i - j + 1);
        }
        return res;
    }
};