#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ---------------------- DFS using Stack --------------------------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res(0);
        if(!root) return res;
        stack<TreeNode*> stk;
        TreeNode* p = root;

        while(p || !stk.empty()){
            // ---- go to deep end first, and store into Stack ------
            while(p){  
                stk.push(p);
                p = p->left;
            }// now Stack stores the most left trail

            p = stk.top(); // the bottom-left Node
            stk.pop();
            res.emplace_back(p->val);
            p = p->right; // go to another way
        }
        return res;
    }
};