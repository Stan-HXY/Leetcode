#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;



/*
The Tribonacci sequence Tn is defined as follows: 
T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
*/

class Solution {
public:
    int tribonacci(int n) {
        if(n <= 2) return (n > 0)? 1 : 0;
        vector<int> num(n+1);
        num[0] = 0; num[1] = 1; num[2] = 1;
        for(int i = 3; i < n; ++i){
            num[i] = num[i-1] + num[i-2] + num[i-3];
        }
        return num[n];
    }
};