#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int e = 0; // end of none 0 number
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                int temp  = nums[e];
                nums[e] = nums[i];
                nums[i] = temp;
                ++e;
            }
        }
        return;
    }
};