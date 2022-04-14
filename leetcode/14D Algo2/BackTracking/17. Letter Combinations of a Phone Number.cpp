#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number 
could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

class Solution {
public:

    vector<string> res;
    unordered_map<int, string> M = {{2, "abc"}, 
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},  
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        string curr = "";  
        backtrack(curr, 0, digits);
        return res;
    }

    void backtrack(string& curr, int n, string digits){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }
        int count = digits[n] - '0';
        string currdigit = M[count];
        for(int i = 0; i < currdigit.size(); ++i){
            curr.push_back(currdigit[i]);
            backtrack(curr, n+1, digits);
            curr.pop_back();
        }

        return;
    }

    
};