
import java.util.Arrays;

class Solution {
    
    public static void print(Object O){
        System.out.println(O);
        return;
    }
    
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        // if(k == 0) return 0;
        Arrays.sort(nums);
        int res = 0;
        int i = 0;
        int base = 1;
        for(int j = 0; i < nums.length; ++i){
            base *= nums[j];
            while(base >= k){
                base /= nums[i++];
            }
            res += j - i + 1;
        }
        return res;
    }
}