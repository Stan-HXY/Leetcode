#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;


/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dum = new ListNode();
        dum->next = head;
        ListNode* prev = dum;
        ListNode* p = head;     
        while(p != nullptr && p->next != nullptr){
            ListNode* p2 = p->next;
            if(p2->val > p->val){
                p = p->next;
                prev = prev->next;
                continue;
            }
            while(p2 != nullptr){
                if(p2->val > p->val){
                    break;
                }
                p2 = p2->next;
            }
            prev->next = p2;
            p = p2;
        }
        head = dum->next;
        delete dum;
        return head;
    }
};