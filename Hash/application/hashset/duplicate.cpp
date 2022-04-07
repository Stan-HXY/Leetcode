#include<unordered_set>
#include<vector>
using namespace std;

// ==================== using HASHSET =========================
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;

        for(auto &it : nums){
            if (hashset.count(it)){
                return true;
            }
            hashset.insert(it);
        }
        return false;
    }
};


// ==================== SORT the vector =======================
// if there are duplicate, then same number will be adjacent!
class Solution2{
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i){
        // start from SECOND element. Because access i+1 at end is invalid!
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }


};