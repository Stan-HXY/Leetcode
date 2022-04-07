#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
#include<algorithm>
using namespace std;

/*
Given two strings s and t, return true if they are equal 
when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
*/

class Solution1 {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> v1; vector<char> v2;
        return buildString(s) == buildString(t);
    }

    stack<char> buildString(string s){
        stack<char> BS;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '#'){
                BS.push(s[i]);
            }
            else{
                if(BS.empty()) continue;
                BS.pop();
            }
        }
        return BS;
    }
};