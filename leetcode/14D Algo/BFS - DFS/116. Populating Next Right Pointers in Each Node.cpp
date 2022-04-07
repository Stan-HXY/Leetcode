#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;

/*
You are given a perfect binary tree where all leaves are on 
the same level, and every parent has two children. The binary 
tree has the following definition:
*/

struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        queue<Node*> Q;
        int i = 2;
        Q.push(root); Q.push(nullptr);
        while(!Q.empty()){
            for(int n = 0; n < i; ++n){
                Node* p = Q.front();
                Q.pop();
                if(p == nullptr) continue;
                p->next = Q.front();
                if(p->left){
                    Q.push(p->left);
                }
                if(p->right){
                    Q.push(p->right);
                }
            }
            i = i * 2 - 1;
            Q.push(nullptr);
        }
        return root;
    }
}; 