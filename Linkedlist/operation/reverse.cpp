#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int i): val(i), next(nullptr){}
    ListNode(): val(0), next(nullptr){}
};

class MyLinkedList {
public:
    int len;
    ListNode* head;
    ListNode* tail;
    MyLinkedList(): head(nullptr), tail(nullptr) {}
};


class Solution{
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode *p1;
        p1 = head;
        while(head->next){
            ListNode* p2 { head->next };
            head->next = head->next->next;
            p2->next = p1;
            p1 = p2;
        }
        head = p1;
        return head;
    }

};