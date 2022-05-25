import java.util.*;

/*
Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

Input: s = "(()"
Output: 2

Input: s = ")()())"
Output: 4
*/

class Solution {
    public int longestValidParentheses(String s) {
        int res = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '('){
                ++l;
            }
            else ++r;
            
        }
    }
}