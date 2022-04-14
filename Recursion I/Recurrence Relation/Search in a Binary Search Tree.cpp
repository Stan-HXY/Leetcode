#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
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
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the 
subtree rooted with that node. If such a node does not exist, return null.


Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

============== binary search tree =========================
Binary Search Tree is a binary tree where the key in each node:

1. is greater than any key stored in the left sub-tree,
2. and less than any key stored in the right sub-tree.

            2
           / \
          1  33
             / \
           25  40
          /    /
         11   34
        / \    \
       7  12   36
           \
           13       

*/

// ================== recursive ======================================
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val){
            return root;
        }
        return (val < root->val)? searchBST(root->left, val) : searchBST(root->right, val);
    }
};


// ================== iterative ======================================
class Solution1 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        while(root != nullptr && val != root->val){
            root = (val < root->val)? root->left : root->right;
        }
        return root;
    }
};