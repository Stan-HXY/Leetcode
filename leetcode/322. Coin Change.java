import java.util.*;

/*
You are given an integer array coins representing coins of 
different denominations and an integer amount representing 
a total amount of money.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1
*/

class Solution {
    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[] dp = new int[n];
        int mode = amount; int res = -1;
        Arrays.sort(coins);

        for (int i = n - 1; i >= 0; i--) {
            if(i != n - 1){
                dp[i] = mode / coins[i] + dp[i + 1];
            }
            else{
                dp[i] = amount / coins[i];
            }     
            mode = mode % coins[i];
            if(mode == 0){
                return dp[i];
            }
        }
        return res;
    }
}