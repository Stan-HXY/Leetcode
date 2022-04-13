import java.util.ArrayList;
import java.util.List;

class Solution {

    List<String> res = new ArrayList<>();
    char[][] P = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, 
        {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return res; // edge case
        StringBuilder S = new StringBuilder();
        backTrack(digits, 0, S);
        return res;
    }

    public void backTrack(String digits, int i, StringBuilder S){
        if(S.length() == digits.length()){
            res.add(S.toString());
        }
        char[] text = P[digits.charAt(i) - '0'];
        for(char c : text){
            S.append(c);
            backTrack(digits, i+1, S);
            S.deleteCharAt(S.length() - 1);
        }
        return;
    }
}