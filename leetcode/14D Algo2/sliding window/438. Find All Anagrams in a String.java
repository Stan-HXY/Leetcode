import java.util.*;

/*
Given two strings s and p, return an array of all 
the start indices of p's anagrams in s. You may return 
the answer in any order.

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
*/

class Solution {

    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new LinkedList<>();
        if(s.length() < p.length()) return res; 
        int[] Ms = new int[26]; int[] Mp = new int[26]; 
        for (int i = 0; i < p.length(); i++) {
            ++Ms[s.charAt(i) - 'a'];
            ++Mp[p.charAt(i) - 'a'];
        }
        if(Arrays.equals(Ms, Mp)) res.add(0);
//         --------------
        int l = 1, r = p.length();
        while(r < s.length()){
            --Ms[s.charAt(l - 1) - 'a'];
            ++Ms[s.charAt(r) - 'a'];
            if(Arrays.equals(Ms, Mp)){
//             --------------
                res.add(l);
            }
            ++l;
            ++r;
        }
        return res;
    }
}