#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<algorithm>
#include<unordered_set> 
#include<unordered_map> 
using namespace std;


/*
Given the head of a linked list, remove the nth node 
from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ============== Linkedlist Question: Add Dummy Node ===============
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            head = nullptr;
            return head;
        }
        ListNode* dum = new ListNode();
        dum->next = head; // dummy node to avoid edge cases
        ListNode* p1 = dum;
        ListNode* p2 = p1;
        while(p2 != nullptr && p2->next != nullptr){
            if(p1 == p2){
                for(int i = 0; i < n; ++i){
                    p2 = p2->next;
                }
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        ListNode* p3 = p1->next->next;
        p1->next = p3;
        head = dum->next;
        delete dum;
        return head;
    }
};