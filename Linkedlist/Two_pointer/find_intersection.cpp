#include<iostream>
#include<map>
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
    
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode* pA {headA};
        map<ListNode*, int> mA{};
        while(pA){
            mA[pA] = 0;
            pA = pA->next;
        }
        ListNode* pB {headB};
        while(pB){
            if(mA.find(pB) != mA.end()){
                return pB;
            }
            pB = pB->next;
        }
        return nullptr;
    } 




};