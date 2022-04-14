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


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        TreeNode* cur;
        while (!q.empty()) {
            int size = q.size();
            ans.push_back(vector<int>());
            for (int i = 0; i < size; ++i) {		// traverse nodes in the same level
                cur = q.front();
                q.pop();
                ans.back().push_back(cur->val);		// visit the root
                if (cur->left) {
                    q.push(cur->left);				// push left child to queue if it is not null
                }
                if (cur->right) {
                    q.push(cur->right);				// push right child to queue if it is not null
                }
            }
        }
        return ans;
    }
};