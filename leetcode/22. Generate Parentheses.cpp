#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;


/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
public:

    vector<string> res;
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        bt(n, 0, 0, s);
        return res;
    }

    void bt(int n, int o_count, int um_count, string &curr){
        if(curr.size() == 2 * n){       
            res.push_back(curr);
            return;
        }
        // um_count: how many unmatched ( in the curr
        if(o_count < n){
            curr.push_back('(');
            bt(n, o_count + 1, um_count + 1, curr);
            curr.pop_back();
        }
        if(um_count > 0){
            curr.push_back(')');
            bt(n, o_count, um_count - 1, curr);
            curr.pop_back();
        }     
        return;
    }
};