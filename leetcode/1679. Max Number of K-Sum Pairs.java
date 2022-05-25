import java.util.*;

/*
Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
*/

class Solution {

    // ======== O(n): 1 iteration + hashmap =========
    public int maxOperations(int[] nums, int k){
        // ------- M (element, frequency) --------
        HashMap<Integer, Integer> M = new HashMap<>();
        int res = 0;
        for(int i = 0; i < nums.length; i++) {
            int curr = nums[i];
            int need = k - curr;
            // if complement number available or exist before:
            if(M.getOrDefault(need, 0) > 0){
                ++res;
                M.put(need, M.get(need) - 1);
            }
            else{
                M.put(curr, M.getOrDefault(curr, 0) + 1);
            }
        }  
        return res;
    }




    // ======== O(nlogn): sort + 1 iteration =========
    public int maxOperations_1(int[] nums, int k) {
        Map<Integer, Integer> M = new HashMap<>();
        if(nums.length == 1 || k == 1) return 0;
        Arrays.sort(nums);
        int res = 0;
        int l = 0; int r = nums.length - 1;
        while(l < r){       
            int temp = nums[l] + nums[r];
            if(temp == k){
                ++res; 
                // 2 elements is removed, move both pointers
                ++l;
                --r;
            }
            else if(temp < k){
                ++l;
            }
            else{
                --r;
            }
        }
        return res;
    }
}