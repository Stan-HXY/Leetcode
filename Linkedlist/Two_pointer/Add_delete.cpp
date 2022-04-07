#include<iostream>
using namespace std;

class node{
public:
    int val;
    node* next;
    node* previous;
    node(int i): val(i), next(nullptr), previous(nullptr){}
    node(): val(0), next(nullptr), previous(nullptr){}
};

class MyLinkedList {
public:

    int len;
    node* head;
    node* tail;

    MyLinkedList():len(0), head(nullptr), tail(nullptr){}
    // MyLinkedList() {}

    void getNode(int index){ // helper function
        node* p {head};
        for (int i = 0; i < index; ++i ){
            p = p->next;
        }

    }
    
    int get(int index) {
        if ( index > len - 1 ){ return -1; }
        node* p {head};
        for (int i = 0; i < index; ++i ){
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        node* p { new node(val) };
        if(!head){
            head = tail = p;
        }
        else{
            head->previous = p;
            p->next = head;
            head = p;
        }
        ++len;
    }
    
    void addAtTail(int val) {
        node* p { new node(val) };
        if(!head){
            head = tail = p;
        }
        else{
            tail->next = p;
            p->previous = tail;
            tail = p;
        }
        ++len;
    }
    
    void addAtIndex(int index, int val) {
        if( index > len ){
            return;
            }
        else if( index == len ){
            addAtTail(val);
            return;
        }
        else if( index == 0 ){
            addAtHead(val);
            return;
        }
        else{
            node* p {head};
            for (int i = 0; i < index; ++i ){
                p = p->next;
            }
            node* p1 { new node(val) };
            p->previous->next = p1;
            p1->previous = p->previous;
            p1->next = p;
            p->previous = p1;
        }
        ++len;
    }
    
    void deleteAtIndex(int index) {
        if( index > len - 1 ){
            return;
        }
        node* p {head};
        for (int i = 0; i < index; ++i ){
            p = p->next;
        }
        if( p == head ){
            head = p->next;
            if(p->next){
                p->next->previous = nullptr;
            }
            delete p;        
        }
        else if( p == tail ){
            tail = p->previous;
            if(p->previous){
                p->previous->next = nullptr;
            }
            delete p;            
        }
        else{
            node* ppre = p->previous; node* paf = p->next;
            ppre->next = paf;
            paf->previous = ppre;
            delete p;
        }
        --len;
    }
};


int main(){

    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    obj->get(1);
    obj->deleteAtIndex(1);
    obj->get(1);

    return 0;
}



/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */