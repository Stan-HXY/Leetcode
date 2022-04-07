#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<deque>
using namespace std;


// ==================== Recursion (slow) ================================
class Solution {
public:

    bool helper(vector<int>& V, int l, int r){
        if(r+1 == V.size()){
            if(V[l] == V[r]) return true;
            else return false;
        }
        if(r > V.size()) return false;
        if(V[l] == V[r]){
            return helper(V, l-1, r+1);
        }
        return false;
    }


    bool isPalindrome(int x) {
        // convert x into a array
        vector<int> num;
        int& a = x;
        if(a < 0) return false;
        if(a < 10) return true;
        while(a >= 1){
            num.emplace(num.begin(), (a % 10));
            a /= 10;
        }
        // examine the array
        int l{0}, r{0};
       if(num.size() % 2 != 0){
            l = r = num.size()/2;
        }
        else{
            l = num.size()/2 - 1; r = num.size()/2;
        }
        return helper(num, l, r);
    }
};

// ==================== Two-pointer Iteration (faster) ================================
class Solution {
public:

    bool isPalindrome(int x){
        int& a = x;
        if(a < 0) return false;
        if(a < 10) return true;
        // convert x into a array
        vector<int> num;
        while(a >= 1){
            num.emplace(num.begin(), (a % 10));
            a /= 10;
        }
        // examine the array
        int l{0}, r{num.size() - 1};
        while(l < r){
            if(num[l] != num[r]) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }
};