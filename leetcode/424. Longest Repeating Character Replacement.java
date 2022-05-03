import java.util.HashMap;

/*
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
*/





class Solution {

    // =============== use Array instead of Hash ===================
    public int characterReplacement(String s, int k) {
        //HashMap<Character, Integer> M = new HashMap<>();
        int[] M = new int[26];
        int len = s.length();
        int l = 0;
        int max = 0, res = 0;
        for(int r = 0; r < len; ++r){
            Character c = s.charAt(r);
            // update hashmap
            int curr = ++M[c - 'A'];
            // update maximum frequence
            max = Math.max(max, curr);
            // check if current substring is valid
            int window = r - l + 1;
            if(window - max > k){
                // shrink the window by 1
                Character cl = s.charAt(l++);
                --M[cl - 'A']; // update Hashmap
                --window;
            }
            res = Math.max(res, window);
        }
        return res;
    }
}