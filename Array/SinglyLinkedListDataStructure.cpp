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
