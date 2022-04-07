#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// =============== failed ===========================
class Solution {
public:

    double helper(double x, int n, double res){
        if(n == 0) return x;
        return helper(x, n-1, res*x );
    }

    double myPow(double x, int n) {
        return helper(x, n, x);
    }
};