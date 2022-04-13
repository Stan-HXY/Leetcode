import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        int[][] res = new int[m][n];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int horizon = (j + k)%n;
                int circle = (j+k)/n; // number of times this element pass through gate
                int vertic = (i + circle)%m;
                res[vertic][horizon] = grid[i][j]; 
            }
        }
        // -------- convert array to array list ---------
        List<List<Integer>> result = new ArrayList<>();
        for(int i = 0; i < m; ++i){
            List<Integer> temp = new ArrayList<>();
            for(int j = 0; j < n; ++j){
                temp.add(res[i][j]);
            }
            result.add(temp);
        }

        return result;
    }
}