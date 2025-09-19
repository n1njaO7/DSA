#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
    node* prev;
};

class CDLL{
    private:
        node *start;
    public:
        CDLL();
        CDLL(CDLL&);
        CDLL& operator=(CDLL&);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~CDLL(); 
};

CDLL::CDLL(){
    start = NULL;
}

void CDLL :: insertAtStart(int data){
    node *n = new node;
    n->item = data;
    if(start == NULL){
        n->next = n;
        n->prev = n;
        start = n;
    }
    else {
        n->next = start;
        n->prev = start ->prev;
        start->prev->next = n;
        start = n;
    }
    start = n;
}

void CDLL:: insertAtLast(int data){
    node *n = new node;
    n->item = data;
    if (start == NULL) {
        n->prev = n;
        n->next = n;
        start = n;
    }else{
        n->next = start;
        n->prev = start->prev;
        start->prev = n;
        start->prev->next = n;
    }
}

node* CDLL::search(int data){
    node* t;
    if(start == NULL)
        return NULL;
    t= start ;
    do{
        if(t->item == data )
            return t;
        t=t->next;
    }while(t!=start);
    return NULL;
}