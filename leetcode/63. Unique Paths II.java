import java.util.*;

/*
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {

    //======================== DP ==========================
    public int uniquePathsWithObstacles(int[][] obstacleGrid){
        int m = obstacleGrid.length; int n = obstacleGrid[0].length;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        int[][] dp = new int[m + 1];
        dp[1][1] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 0){
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }



    //======================== dfs (Time Limit Exceeded) ==========================
    int[][] direction = {{1, 0}, {0, 1}};
    int res = 0;
    
    public int uniquePathsWithObstacles_1(int[][] obstacleGrid) {
        int m = obstacleGrid.length; int n = obstacleGrid[0].length;
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
        dfs(obstacleGrid, 0, 0, m, n);
        return res;
    }

    public void dfs(int[][] obstacleGrid, int i, int j, int m, int n){   
        if(i == m - 1 && j == n - 1){
            ++res; 
            return;
        }

        for (int[] k : direction) {
            int i1 = i + k[0]; int j1 = j + k[1];
            if(i1 < m && j1 < n && obstacleGrid[i1][j1] != 1){
                System.out.println(i1 + " " + j1);
                dfs(obstacleGrid, i1, j1, m, n);
            }
        }
        return;
    }
}
