#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;


/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/



class Solution {
public:

    void helper(vector<char>& s, int i, int j){
        if(i >= j) return;
        // char temp = s[i];
        // s[i] = s[j];
        // s[j] = temp;
        swap<char>(s[i], s[j]);
        helper(s, i+1, j-1);
        return;
    }

    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
        return;
    }


};