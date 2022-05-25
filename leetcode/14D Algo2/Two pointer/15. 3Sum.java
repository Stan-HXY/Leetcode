import java.util.*;


/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/


class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length; 
        List<List<Integer>> res = new ArrayList<>();
        if(n < 3) return res; 
        Arrays.sort(nums);
        int end  = n - 1;
        for (int i = 0; i < nums.length; i++) {
            if(i == 0 || nums[i - 1] != nums[i]){
                int next = i + 1;     
                while(next < end){
                    int sum = nums[i] + nums[next] + nums[end];
                    if(sum == 0){
                        List<Integer> m = Arrays.asList(nums[i], nums[next], nums[end]);
                        res.add(m);
                        ++next;
                        while(next < end && nums[next - 1] == nums[next]){
                            ++next;
                        }
                    }
                    else if(sum < 0){
                        ++next;
                    }
                    else if(sum > 0){
                        --end;
                    }
                }
                
            }
        }
        return res;
    }
}