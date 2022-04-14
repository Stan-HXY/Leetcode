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
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

------ example ------
Input: root = [1,2,2,3,4,4,3]
Output: true
*/

class Solution {
public:

    bool helper(TreeNode* rl, TreeNode* rr){
        if(rl == nullptr && rr == nullptr) return true; 
        /*
        If both treeNode are empty, then they are mirror node
        */
        if(rl && rr && rl->val == rr->val){
            return helper(rl->left, rr->right) && helper(rl->right, rr->left); // if both true, then true
        }
        /*
        For two trees to be mirror images, the following three conditions must be true:
        1 - Their root node's key must be same 
        2 - left subtree of left tree and right subtree of right tree have to be mirror images
        3 - right subtree of left tree and left subtree of right tree have to be mirror images
        */
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};