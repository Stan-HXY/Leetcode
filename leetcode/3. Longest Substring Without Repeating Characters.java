import java.util.HashMap;

/*
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Input: s = "pwwkew"
Output: 3, "kew"
*/


class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n < 2) return n;
        HashMap<Character, Integer> M = new HashMap<>();
        int res = 0, l = 0, r = 0;
        while(r < n){          
            if(!M.containsKey(s.charAt(r)) || M.get(s.charAt(r)) < l){
                M.put(s.charAt(r), r);
            }
            else{
                l = M.get(s.charAt(r)) + 1;
                M.replace(s.charAt(r), r);
            }
            res = Math.max(r - l + 1, res);
            ++r;
        }
        return res;
    }
}