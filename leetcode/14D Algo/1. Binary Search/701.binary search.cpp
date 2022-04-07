#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

// ======================== binary search ===========================
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }   
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }
        int l = 0; int r = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while(l != r){
            int m = (r - l)/2;
            if(nums[l] == target || nums[r] == target){
                return (nums[l] == target)? l : r;
            }
            if(nums[m] == target) return m;
            else if(nums[m] > target){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return -1;
    }
};