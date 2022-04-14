#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;


/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the 
sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
*/

class Solution {
public:
    unordered_map<int, int> M;
    int fib(int n) {
        if(n < 2) return n;
        if(M.find(n) != M.end()){
            return M[n];
        }
        int res;
        res = fib(n-1)+fib(n-2);
        M[n] = res;
        return res;
    }
};

