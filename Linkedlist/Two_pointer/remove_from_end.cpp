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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        if(!head) return nullptr;
        ListNode* dummy { new ListNode() };
        dummy->next = head;

        ListNode*p1, *pend;
        p1 = pend = dummy;
        for(int i = 0; i < n; ++i){
            pend = pend->next;
        }
        while(true){
            if( !pend->next ){
                ListNode* p1af = p1->next;
                p1->next = p1->next->next;
                delete p1af;
                break;
            }
            pend = pend->next;
            p1 = p1->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }

    // using hasp map -------- unordered_map < int pos, *Node >
    ListNode* hm_removeNthFromEnd(ListNode* head, int n) {
        // hash table  map<position of node , node address> 
        if(head==NULL) return NULL; 
        if(head->next==NULL) return NULL; 
        unordered_map<int, ListNode*> mp ; // unordered_map, each element is a pair
        int index =0 ; 
        ListNode* temp=head; 
        while(temp){
            index++; 
            mp.insert(make_pair(index, temp)); 
            temp = temp->next ; 
            
        }
        // i need l-n+1 the node from the 
        temp = mp[index-n+1]; 
        if(temp==head){
            // remove first element 
            head = temp->next; 
          
        }else if(n==1){
            temp = mp[index-1]; 
            temp->next = NULL; 
        }else{
            mp[index-n]->next = temp->next;
        }
        return head; 
        
    }




};