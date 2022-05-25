import java.util.LinkedList;
import java.util.*;

/*
An island is surrounded by water and is formed by 
connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
*/

class Solution {
    // --------------- use DFS ----------------
    public int numIslands(char[][] grid) {
        int m = grid.length; int n = grid[0].length;
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    public void dfs(char[][] g, int i, int j){
        if(i >= 0 && i < g.length && j >= 0 && j < g[0].length && g[i][j] != '0'){
            g[i][j] = '0';
            int[][] directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
            for(int[] t : directions){
                dfs(g, i + t[0], j + t[1]);
            }
        }
        return;
    }


    public void bfsMark(char[][] g, int i, int j){
        Queue<int[]> Q = new LinkedList<>();
        int[][] directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        Q.add(new int[]{i, j});
        while(!Q.isEmpty()){
            int[] temp = Q.poll();
            int r = temp[0]; int c = temp[1];
            for(int[] d : directions){
                int rt = r + d[0];
                int ct = c + d[1];
                if(rt >= 0 && rt < g.length && ct >= 0 && ct < g[0].length && g[rt][ct] != '0'){
                    Q.add(new int[]{rt, ct});
                    g[rt][ct] = '0';
                }
            }
        }
        return;
    }
}