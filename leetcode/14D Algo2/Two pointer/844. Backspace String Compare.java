import java.util.*;

/*
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/

class Solution {
    public boolean backspaceCompare(String s, String t) {
        int n1 = s.length(), n2 = t.length();
        int n = Math.max(n1, n2);
        StringBuilder s1 = new StringBuilder();
        StringBuilder t1 = new StringBuilder();
        int i = 0;
        while(i < n){
            if(i < n1){
                if(s.charAt(i) == '#' && s1.length() != 0){
                    s1.deleteCharAt(s1.length() - 1);
                }
                else if(s.charAt(i) != '#'){
                    s1.append(s.charAt(i));
                }
            }
            if(i < n2){
                if(s.charAt(i) == '#' && t1.length() != 0){
                    t1.deleteCharAt(t1.length() - 1);
                }
                else if(s.charAt(i) != '#'){
                    t1.append(s.charAt(i));
                }
            }
            ++i;
        }
        return s1.toString().equals(t1.toString());
    }
}