#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class SLL{
    private:
        node *start;
    public:
        SLL();
        SLL(SLL&);
        SLL& operator=(SLL&);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~SLL(); 
};

SLL::SLL(){
    start = NULL;
}
void SLL :: insertAtStart(int data){
    node *n=new node;
    n->item = data;
    n->next = start;
    start = n;
}

void SLL :: insertAtLast(int data ){
    node *t;
    node *n =new node ;
    n->item = data;
    n->next = NULL;
    if(start == NULL)
        start = n;
    else{
        while (t->next != NULL)
            t=t->next;
        t->next = n;
    }
}

node* SLL :: search(int data){
    node *t;
    t=start;
    while(t){
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}

void SLL :: insertAfter(node *t , int data){
    node *n;
    if(t){
        n =new node ;
        n->item = data;
        n->next = t->next;
        t->next = n;
    }
}
