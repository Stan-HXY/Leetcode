import java.util.*;

/*
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have 
to wait after the ith day to get a warmer temperature. If there is no future 
day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
*/

class Solution {
    public int[] dailyTemperatures(int[] t) {
        Stack<int[]> S = new Stack<>();
        int[] res = new int[t.length];
        for (int i = 0; i < t.length; i++) {
            while(!S.isEmpty() && S.peek()[0] < t[i]){
                int[] temp = S.pop();
                res[temp[1]] = i - temp[0];
            }
            S.add(new int[]{t[i], i});
        }
        return res;
    }
}