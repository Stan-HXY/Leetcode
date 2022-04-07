#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;

/*
Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Input: s = "()[]{}"
Output: true
*/

// -------------- using Stack -----------------
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n == 1) return false;
        stack<char> S;
        //S.push({0, s[0]});
        for(int i = 0; i < n; ++i){
            if(S.empty()){
                S.push(s[i]);
                continue;
            }
            char top = S.top();
            if(s[i] == ']'){
                if(top != '['){
                    return false;
                }
                else{
                    S.pop();
                }
            }
            else if(s[i] == '}'){
                if(top != '{'){
                    return false;
                }
                else{
                    S.pop();
                }
            }
            else if(s[i] == ')'){
                if(top != '('){
                    return false;
                }
                else{
                    S.pop();
                }
            }
            else{
                S.push(s[i]);
            }
        }
        return true;
    }
};



class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 1 || s[0] == ']' || s[0] == ')' || s[0] == '}') return false;
        unordered_map<char, int> M;
        for(int i = 0; i < s.size(); ++i){
            // if(M.find(s[i]) != M.end())
            if(s[i] == ']'){
                if(M['['] != 0){
                    --M['['];
                }
                else return false;
            }
            else if(s[i] == '}'){
                if(M['{'] != 0){
                    --M['{'];
                }
                else return false;
            }
            else if(s[i] == ')'){
                if(M['('] != 0){
                    --M['('];
                }
                else return false;
            }
            else{
                ++M[s[i]];
            }
        }
        return M.empty();
    }
};