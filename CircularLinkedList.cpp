#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class CLL{
    private:
        node *last;
    public:
        CLL();
        CLL(CLL&);
        CLL& operator=(CLL&);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~CLL(); 
};

CLL::CLL(){
    last = NULL;
}

void CLL::insertAtStart(int data){
    node *n= new node;
    n->item = data;
    if(last==NULL){
        n->next=n;
        last =n;
    }else{
        n->next = last->next;
        last->next = n;

    }
}

void CLL :: insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if(last==NULL){
        n->next=n;
        last = n;
    }
    else{
        n->next = last->next;
        last->next = n;
        last = n;
    }
}