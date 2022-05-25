import java.util.*;

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
    public int maxArea(int[] h) {
        int res = 0;
        int l = 0, r = h.length - 1;
        while(l < r){
            int curr = Math.min(h[l], h[r]);
            res = Math.max(res, (r - l) * curr);
            if(h[l] <= h[r]){
                ++l;
            }
            else ++r;
        }
        return res;
    }
}