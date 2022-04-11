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

    // ---------------- recursion ------------------
    // int index = 0; 
    // public String decodeString(String s) {
    //     StringBuilder res = new StringBuilder();
    //     while(index < s.length() && s.charAt(index) != ']') {
    //         if(! Character.isDigit(s.charAt(index))) {
    //             res.append(s.charAt(index));
    //             index++;
    //         } else {
    //             int count = 0;
    //             while(index < s.length() && Character.isDigit(s.charAt(index))) {
    //                 count = count * 10 + s.charAt(index) - '0';
    //                 index++;
    //             }
    //             index++; //numbers are done and next should be '['
                
    //             // build substring 
    //             String decoded = decodeString(s);
                
    //             index++;
    //             while(count-- > 0)
    //                 res.append(decoded);
    //         }
    //     }
    //     return new String(res);
    // }


    // ------------ two stack ---------------
    public String decodeString(String s){
        Stack<Integer> intStack = new Stack<>(); // record multiplier
        Stack<StringBuilder> strStack = new Stack<>(); // record string
        StringBuilder currStr = new StringBuilder();
        StringBuilder currInt = new StringBuilder();
        for(Character i : s.toCharArray()){
            if(Character.isDigit(i)){
                currInt.append(i);
            }
            else if(Character.isAlphabetic(i)){
                currStr.append(i);
            }
            else if(i == '['){ // means prev string and next string is not sychronized, preserve prev string
                if(currStr.length() > 0){
                    strStack.push(currStr);
                }
                intStack.push(Integer.parseInt(currInt.toString()));
                currStr = new StringBuilder();
                currInt = new StringBuilder();
            }
            else if(i == ']'){
                int count = intStack.pop();
                StringBuilder prevStr = strStack.pop(); // get previous string
                while(count-- > 0){
                    prevStr.append(currStr);
                }
                currStr = prevStr; 
            }
        }
        return currStr.toString();
    }


    // ------------- one Stack (high TC) ---------------
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