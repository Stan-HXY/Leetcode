import java.util.*;




class Solution {

    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if(n == 1) return 1;
        if(grid[0][0] == 1) return -1;
        int res = 1;
        Queue<int[]> Q = new LinkedList<>();
        int[][] directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        Q.add(new int[]{0, 0});
        while(!Q.isEmpty()){
            int len = Q.size();
            ++res;
            for(int i = 0; i < len; ++i){
                int[] temp = Q.poll();
                grid[temp[0]][temp[1]] = 1;
                for(int[] d : directions){
                    int r = temp[0] + d[0];
                    int c = temp[1] + d[1];
                    if(r == n - 1 && c == n - 1) return res;
                    if(r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 0){
                        Q.add(new int[]{r, c});
                        grid[r][c] = 1;
                    }
                }
            }     
        }
        return -1;
    }


















    // bfs

    public int[][] directions = {{0,1}, {1,1}, {1, 0}, {0, -1}, 
                            {1, -1}, {-1, 0}, {-1, 1}, {-1, -1}};


    public int shortestPathBinaryMatrix_1(int[][] grid){
        int len = grid.length;
        if(grid[0][0] == 1 || grid[len - 1][len - 1] == 1) return -1;
        Queue<int[]> Q = new LinkedList<>();
        Q.add(new int[]{0, 0});
        grid[0][0] = 1;
        while(!Q.isEmpty()){
            int r = Q.peek()[0], c = Q.peek()[1];
            int dist = grid[r][c];
            for(int i[] : directions){
                int rt = r + i[0], ct = c + i[1];
                if(rt == len - 1 && ct == len - 1) return dist + 1;
                if(rt >= 0 && rt < len && ct >= 0 && ct < len && grid[rt][ct] == 0){
                    grid[rt][ct] = dist + 1;
                    Q.add(new int[]{rt, ct});
                }
            }
        }
        return -1;
    }


    public int shortestPathBinaryMatrix2(int[][] grid) {
        int len = grid.length;
        if(grid[0][0] == 1 || grid[len - 1][len - 1] == 1) return -1;
        int res = 1;
        Queue<int[]> Q = new LinkedList<>();
        Q.add(new int[]{0, 0});
        grid[0][0] = 1;
        while(!Q.isEmpty()){   
            for(int j = 0; j < Q.size(); ++j){
                int r = Q.peek()[0], c = Q.peek()[1];
                Q.poll();
                for(int[] i : directions){
                    int rt = r + i[0], ct = c + i[1];
                    if(rt == len - 1 && ct == len - 1) return ++res;
                    if(rt >= 0 && rt < len && ct >= 0 && ct < len && grid[rt][ct] == 0){     
                        Q.add(new int[]{rt, ct});
                        grid[rt][ct] = 1;    
                    }
                }
            }
            ++res;        
        }
        return -1;
    }
}