import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Solution {

    /*
    Input: s = "3[a]2[bc]"
    Output: "aaabcbc"

    Input: s = "3[a2[c]]"
    Output: "accaccacc"

    Input: s = "2[abc]3[cd]ef"
    Output: "abcabccdcdcdef"
    */

    public String decodeString_2(String s) {
        Stack<Character> S = new Stack<>();  
        for(int i = 0; i < s.length(); ++i){
            if(s.charAt(i) != ']') S.add(s.charAt(i));
            else{
                StringBuilder curr = new StringBuilder();
                // get current string in [ ]
                while((!S.isEmpty()) && Character.isAlphabetic(S.peek())){
                    curr.insert(0, S.pop());
                }
                if(S.peek() == '[') S.pop();

                // get current repeat times
                StringBuilder times = new StringBuilder(); 
                while((!S.isEmpty()) && Character.isDigit(S.peek())){
                    times.insert(0, S.pop());
                }
                if(times.length() == 0) continue;
                int count = (times.length() == 0)? 1 : Integer.parseInt(times.toString());

                // put current string back to stack
                while(count-- > 0){
                    for(char c : curr.toString().toCharArray()){
                        S.add(c);
                    }
                }
            }
        }
        // traverse back to Stack to get result
        StringBuilder res = new StringBuilder();
        while(!S.isEmpty()){
            res.insert(0, S.pop());
        }
        return res.toString();
    }
    
}