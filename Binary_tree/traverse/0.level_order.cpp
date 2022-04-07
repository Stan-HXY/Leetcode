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
Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).

------ example ------
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
*/


class Solution {
public:

    // need to call by reference when pass in the vector
    void helper(TreeNode* root, vector<vector<int>>& res, int level){
        if(root == nullptr) return;
        if(level >= res.size() ) { // if level hasn't stored, create vector for level
            vector<int> V{};
            res.push_back(V); // if level < size, then this level isn't finished yet
        }
        res[level].push_back(root->val); // insert val to the level which this node belongs to
        helper(root->left, res, level+1);
        helper(root->right, res, level+1);
        return;                          
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return {};
        helper(root, res, 0);
        return res;
    }
};