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
Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.
(leaf is considered a univalue tree)

------ example ------
Input: root = [5,1,5,5,5,null,5]
Output: 4
*/

class Solution {
public:

    int i = 0;
    bool helper(TreeNode* root, int val){
        if(root == nullptr) return true;

        if( !helper(root->left, root->val) || !helper(root->right, root->val) ){
            return false;
        }
        // otherwise, count + 1
        i += 1;
        return root->val == val;
    }



    int countUnivalSubtrees(TreeNode* root) {
        helper(root, 0);
        return i;
    }



};