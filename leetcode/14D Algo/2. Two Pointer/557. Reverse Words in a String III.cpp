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
Given a string s, reverse the order of characters 
in each word within a sentence while still preserving 
whitespace and initial word order.

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/


class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        int start = 0;
        for(int i = 0; i < size; ++i){
            if(s[i+1] == ' ' || i == size - 1){
                int r = i;
                while(start <= r){
                    swap(s[start], s[r]);
                    ++start;
                    --r;
                }
                start = i + 2;
            }
        }
        return s;
    }
};