#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;



// ===================== Dynamic programming ========================
class Solution2 {
public:
    /*
    1 step : 1 [1] 
    2 step : 2 [11, 2]
    3 step : 3 [111, 21, 12]
    4 step : 5 [1111, 211, 121, 112, 22]  

    (i-1) -> i [1 kind of way(all way to i-1 + 2)] 
    (i-2) -> i [1 kind of way(all way to i-2 + 1)] if i-2 + 1, will overlap with (i-1)-> i    
    */
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> step(n+1);
        step[0] = 0; step[1] = 1; step[2] = 2;
        for(int i = 3; i < n+1; ++i){
            step[i] = step[i - 1] + step[i - 2];
        }
        return step[n];
    }
};


// ================= simple Recursion ======================
class Solution1{
public:
    int climbStairs(int n){
        return helper(0, n);
    }
    unordered_map<int, int> record;
    int helper(int i, int n){
        if(i > n) return 0;
        if(i == n) return 1;
        if(record.find(i) != record.end()) return record[i];
        record[i] = helper(i + 1, n) + helper(i + 2, n);
        return record[i];
    }

};

// =================== recursion with Memo ======================
class Solution{
public:

    int helper(unordered_map<int, int> M, int i, int step){
        if(step == i) return 1;
        if(step > i) return 0;
        // if we see this step before, just return recorded result
        if(M.find(step) != M.end()) return M[step]; 
        M[step] = helper(M, i, step + 1) + helper(M, i, step + 2);
        return M[step];
    }


    int climbStairs(int n){
        unordered_map<int, int> M;
        return helper(M, n, 0);
    }

};