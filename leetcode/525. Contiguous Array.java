import java.util.HashMap;

class Solution {
    
    
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        if(n < 2) return 0;
        int sum = 0, res = 0; // 1:1, 0:-1
        HashMap<Integer, Integer> M = new HashMap<>();
        M.put(0, -1);
        for(int i = 0; i < n; ++i){
            sum += (nums[i] == 1)? 1 : -1;
            if(M.containsKey(sum)){
                res = Math.max(res, i - M.get(sum))
            }
            else{
                M.put(sum, i);
            }
        }
        return res;    
    }
}