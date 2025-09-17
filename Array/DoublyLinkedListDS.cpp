#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
    node* prev;
};

class DLL{
    private:
        node *start;
    public:
        DLL();
        DLL(DLL&);
        DLL& operator=(DLL&);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~DLL(); 
};

DLL::DLL(){
    start = NULL;
}

DLL :: DLL(DLL &list){
    node *t;
    t = list.start;
    start =NULL;
    while (t){
        insertAtLast(t->item);
        t =t->next;
    }
}

DLL& DLL:: operator=(DLL& list){
    node *t;
    t=list.start;
    while (start)
        deleteFirst();
    while(t){
        insertAtLast(t->item);
        t=t->next;
    }
    return *this;
    
}

void DLL :: insertAtStart(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    n->prev = NULL;
    if (start != NULL) {
        start->prev = n;
    }
    start = n;
}

void DLL:: insertAtLast(int data){
    node *t;
    t= start;
    node *n = new node;
    if (start == NULL) {
        n->prev = NULL;
        start = n;
    }else{
        n->item = data;
        n->next = NULL;
        while(t->next != NULL)
            t= t->next;
        n->prev = t;
        t->next = n;
    }
}

void DLL:: insertAfter(node *t,int data){
    node *n = new node;
   if (t == NULL) {
        cout << "Given node cannot be NULL" << endl;
        return;
    }
    n->item = data;
    n->next = t->next;
    n->prev = t;
    t->next = n;
    if (n->next != NULL) {
        n->next->prev = n;
    }
}

node* DLL::search(int data){
    node* t;
    t= start ;
    while(t->next!= NULL){
        if(t)
            return t;
        t=t->next;
    }
    return NULL;
}

void DLL :: deleteFirst(){
    node *n = start;
    start = n->next;
    if(start){
        start->prev = NULL;
    }
    delete n;
}
 