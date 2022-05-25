import java.util.*;

/*
Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is 
{"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
*/

class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] a = new int[strs.length];
        for (int i = 0; i < strs.length; i++) {
            int count1 = 0, count0 = 0;
            int len = strs[i].length();
            for(int j = 0; j < strs[i].length(); ++j){
                if(strs[i].charAt(j) == 1) ++count1;
                else ++count0;
            }
            a[i] = new int[]{count0, count1, len};
        }
        int res = 0; int count0 = a[0][0], count1 = a[0][1];
        int l = 0, r = 0;
        
    }
}