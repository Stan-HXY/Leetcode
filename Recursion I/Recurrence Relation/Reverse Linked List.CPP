#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<String>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){} return nullptr;
        if(!head->next){
            return head;
        }
        ListNode* p = reverseList(head->next);
        p->next = head;
        head->next = nullptr;
        return p;
    }
};


// failed ------------------------------
class Solution1 {
public:

    ListNode* helper(ListNode* head, ListNode* ptemp) {
        if(!head){} return nullptr;
        if(!head->next){
            ptemp = head;
            return head;
        } 
        helper(head->next, ptemp)->next = head;
        return head;
    }
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p = head->next;
        reverseList(head->next)->next = head;
        return p;
    }

};



