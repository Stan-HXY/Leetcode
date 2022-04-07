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

// ================ top -> down ====================
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode* l, TreeNode* r){
        if(l == nullptr && r == nullptr) return true;
        if(!l && r) return false;
        if(!r && l) return false;
        if(l->val == r->val) {
            return check(l->left, r->right) && check(l->right, r->left);
        }
        else return false;
    }
};