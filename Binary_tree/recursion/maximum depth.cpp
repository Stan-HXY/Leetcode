#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Given the root of a binary tree, return its maximum depth.

------ example ------

*/


class Solution_2{
public:
    // =============== BEST SOLUTION (Down -> top) ==================
    int helper(TreeNode* root, int depth){
        if(root == nullptr) return depth; // return the parameter "depth"
        return max( helper(root->left, depth + 1), helper(root->right, depth + 1) );
    }

    int maxDepth(TreeNode* root) {
        return helper(root, 0);
    }
};


class Solution {
public:

    // =============== top -> down(update in everystep) ==================
    int answer = 0;

    int helper(TreeNode* root, int depth) {
        if(root == nullptr) return 0;
        answer = max(answer, depth);  
        helper(root->left, depth + 1);
        helper(root->right, depth + 1);
        return answer;
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return helper(root, 1);
    }
};

