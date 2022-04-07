#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
Given two strings text1 and text2, return the length of their  common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The  common subsequence is "ace" and its length is 3.
*/


class Solution {
public:
    int CommonSubsequence(string text1, string text2) {
        vector<vector<int>> DP(text1.size(), vector<int>(text2.size()));
        DP[0][0] = (text1[0] == text2[0])? 1 : 0; // start point

        for(int i = 1; i < text1.size(); ++i){
            for(int j = 1; j < text2.size(); ++j){
                if(text1[i] == text2[j]){
                    DP[i][j] = 1 + DP[i-1][j-1];    
                }
            }
        }
        

    }
};