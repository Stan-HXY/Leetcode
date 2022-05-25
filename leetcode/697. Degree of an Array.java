import java.util.*;

/*
Given a non-empty array of non-negative integers nums, 
the degree of this array is defined as the maximum frequency 
of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) 
subarray of nums, that has the same degree as nums.

Input: nums = [1,2,2,3,1,4,2]
Output: 6
Explanation: 
The degree is 3 because the element 2 is repeated 3 times.
So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
*/

class Solution {

    // ============= one pass solution ================
    public int findShortestSubArray(int[] nums) {
        /*
        hashmap with element be keys and [1st occurence, last occurence, frequency] is value
        */
        Map<Integer, int[]> M = new HashMap<>();
        // keep record max value in each step
        int max = 0, res = 0;
        for(int i = 0; i < nums.length; ++i){
            if(!M.containsKey(nums[i])){
                M.put(nums[i], new int[]{i, i, 1});
                max = (max == 0)? 1 : max;
                res = (res == 0)? 1 : res; // at least 1 of length
            }
            else{
                int[] temp = M.get(nums[i]);
                temp[1] = i; // update last occurence position
                ++temp[2];
                // if new max frequency appear
                if(max < temp[2]){
                    max = temp[2];
                    res = temp[1] - temp[0] + 1;
                }
                // if max frequency is equal, compare the length
                else if(max == temp[2]){
                    res = Math.min(res, temp[1] - temp[0] + 1);
                }   
            }         
        }
        return res;
    }
}