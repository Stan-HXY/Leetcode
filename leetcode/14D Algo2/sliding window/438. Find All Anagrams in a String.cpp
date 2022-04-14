#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given two strings s and p, return an array of all the 
start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging 
the letters of a different word or phrase, typically using all the original letters exactly once.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res(0);
        if(p.size() > s.size()) return res;
        int len = p.size();
        vector<char> pd(26, 0);
        vector<char> sd(26, 0);
        int i = 0;
        for(i; i < p.size(); ++i){
            ++pd[p[i] - 'a'];
            ++sd[s[i] - 'a'];
        }
        if(pd == sd){
            res.push_back(0);
        }
        while(i < s.size()){
            --sd[s[i - len] - 'a'];
            ++sd[s[i] - 'a'];
            if(pd == sd){
                res.push_back(i - len + 1);
            }  
            ++i;
        }
        return res;      
    }
}; 