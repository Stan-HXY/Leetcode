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
Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum.


------ example ------
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
*/

class Solution {
public:
    // decrease target everytime by volume of "val", check if target = 0 when hit leaf
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;

        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == 0) return true;
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

