import java.util.Arrays;

/*
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

class Solution {
    
    public boolean checkInclusion(String s1, String s2) {
        if(s1.length() > s2.length()) return false;
        int[] s1map = new int[26];
        int[] s2map = new int[26];
        for(int i = 0; i < s1.length(); ++ i){
            ++s1map[s1.charAt(i) - 'a'];
            ++s2map[s2.charAt(i) - 'a'];
        }
        int l = 0, r = s1.length();
        while(r < s2.length()){
            if(Arrays.equals(s1map, s2map)){
                return true;
            }
            ++s2map[s2.charAt(r++) - 'a'];
            --s2map[s2.charAt(l++) - 'a'];
        }
        return Arrays.equals(s1map, s2map);
    }
}