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


class Solution {
public:
    vector<int> res;
    vector<int> PostorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        res.emplace_back(root->val);
        return res;
    }
};