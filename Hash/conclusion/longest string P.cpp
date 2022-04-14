#include<unordered_map>
#include<String>
#include<iostream>
using namespace std;




/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int i = 0, j = 0;
        unordered_map<char, int> M;
        while(j < s.size()){
            // detect repeated char, and repeated char is after i
            if(M.find(s[j]) != M.end() && M[s[j]] >= i){ 
                i = M[s[j]] + 1; // make i exceed the repeated char's
            }

            else{
                M[s[j]] = j;
                answer = max(answer, j - i + 1);
                ++j;
            }
        }
        return answer;
    }
};