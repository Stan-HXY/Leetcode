#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;



/*
Given a string s, find the length of the  substring without repeating characters.

--- example ----
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


becbasc

*/


class Solution { // official
public:
    int lengthOfSubstring(string s) {
        unordered_map<char, int> M;
        int answer = 0;
        for(int i = 0, j = 0; j < s.size(); ++j){
            if(M.find(s[j]) != M.end()){
                i = max(M[s[j]], i);
            }
            answer = max(answer, j - i + 1);
            M[s[j]] = j + 1;
        }        
        return answer;
    }
};

int main(){
    Solution s;
    string str = {"pwwkew"};
    cout << s.lengthOfSubstring(str) << endl;

    return 0;
}

class Solution1 { // sliding window
public:
    int lengthOfSubstring(string s) {
        int i = 0, j = 0, sz = s.size();
        int len = 0;
        unordered_set<int> us;
        while(j<sz)
        {
            if(us.count(s[j]) > 0){ 
                us.erase(s[i]); 
                ++i;
            }
            else{
                us.insert(s[j]); 
                ++j;
                len = max(len, j-i);
            }
        }
        return len;
    }
};


class Solution1 { // failed on " " (space)
public:

    int lengthOfSubstring(string s) {
        if(s.empty()) return 0;
        set<int, greater<int>> res;
        unordered_map<char, int> M;
        vector<int> record;
        bool random = true;
        for(int i = 0; i < s.size(); ++i){
            if( M.find(s[i]) != M.end() ){
                random = false;
                record.push_back(i);
                res.insert(i - M[s[i]]);
            }
            M[s[i]] = i;
        }
        if(random) res.insert(s.size());

        res.insert(s.size() - *(record.end()-1));

        if(!record.empty())  res.insert(*(record.begin()));

        return *(res.begin());
    }

};



class Solution3 { // Vector solution
public:
    int lengthOfSubstring(string s){
        set<int, greater<int>> res;
        vector<char> dict;
        for(int i = 0; i < s.size(); ++i) {
            auto it = find(dict.begin(), dict.end(), s[i]);
            if(it != dict.end()){
                res.insert(it - dict.begin()); //
                dict.erase(dict.begin(), it+1);  // erase[ a, b )
                dict.push_back(s[i]);
            }
            else{
                dict.push_back(s[i]);
            }
        }
        res.insert(dict.size());
        return *(res.begin());
    }


};
