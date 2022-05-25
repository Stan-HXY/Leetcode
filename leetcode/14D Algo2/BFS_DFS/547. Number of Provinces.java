import java.util.*;

/*
nput: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
*/

class Solution {
    // ======================= dfs =======================
    public int findCircleNum(int[][] isConnected) {
        int[] visited = new int[isConnected.length];
        int res = 0;
        for (int i = 0; i < visited.length; i++) {
            if(visited[i] == 0){
                ++res;
                dfs(isConnected, visited, i);
            }
        }
        return res;
    }

    public void dfs(int[][] C, int[] visited, int i){
        if(visited[i] == 0){
            visited[i] = 1;
            for (int j = 0; j < visited.length; j++) {
                if(i != j && C[i][j] == 1){
                    dfs(C, visited, j);
                }
            }
        }
        return;
    }
}