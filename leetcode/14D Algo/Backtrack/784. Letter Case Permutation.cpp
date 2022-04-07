#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
iven a string s, you can transform every letter 
individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could 
create. Return the output in any order.

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]

Input: s = "3z4"
Output: ["3z4","3Z4"]
*/

class Solution {
public:
    vector<string> ans; 

    void BackTrack(int id, string curr, string s){
        if(curr.size() >= s.size()){
            ans.push_back(curr);
            return;
        }
        // if it's a number, proceed to next index
        if(isdigit(s[id])){
            curr += s[id];
            BackTrack(id + 1, curr, s); 
        }
        else{  
            // --- uppercase ---    
            char temp1 = toupper(s[id]);
            BackTrack(id + 1, curr + temp1, s);
            // --- lowercase ---
            char temp2 = tolower(s[id]);
            BackTrack(id + 1, curr + temp2, s);
        }
        return;
    }

    vector<string> letterCasePermutation(string s) {
        BackTrack(0, "", s);
        return ans;
    }
};
