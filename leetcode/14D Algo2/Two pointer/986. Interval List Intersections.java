import java.util.*;


/*

*/


class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        int m = firstList.length, n = secondList.length;
        List<int[]> res = new ArrayList<>();
        int i = 0, j = 0;

        while(i < m && j < n){
            int max0 = Math.max(firstList[i][0], secondList[j][0]);
            int min1 = Math.min(firstList[i][1], secondList[j][1]);
            if(max0 <= min1){
                int[] temp = {max0, min1};
                res.add(temp);
            }
            if(firstList[i][1] <= secondList[j][1]){
                ++i;
            }
            else ++j;
        }

        return res.toArray(new int[res.size()][]);
        // convert list to array
    }
}