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

void DLL :: insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->item = data;
    n->prev = NULL;
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