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

CDLL :: CDLL(CDLL &list){
    node *t;
    if(list.start!=NULL){
        t = list.start;
        while(t->next!=NULL)
            t=t->next;
        while (t){
            insertAtStart(t->item);
            t =t->prev;
        }
    }
    else{
        start=NULL;
    }
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

void CDLL:: insertAfter(node *t,int data){
   node *n = new node;
   if (t == NULL || t==NULL) {
        cout << "Given node cannot be NULL" << endl;     
    }
    else{
        n->item = data;
        n->next = t->next;
        n->prev = t;
        t->next = n;
        t->next->prev = n;
    }
}

void CDLL :: deleteFirst(){
    node *n ;
    if(start !=NULL){
        n= start;
        if(start->next == start){
            delete start;
            start =NULL;
        }
    else {
        start ->prev -> next = n->next;
        start ->next ->prev = start->prev; 
        start ->prev = n->next;
        delete n;
        }
    }
}

void CDLL :: deleteLast(){
    node *r;
    if(start !=NULL){
        if(start->next == start){
            delete start;
            start =NULL;
        }
        else{
            r = start->prev;
            r->prev ->next = start;
            start ->prev =r->prev;
            delete r;
        }
       
    }
}

void CDLL :: deleteNode(node *t){
    if(start==NULL || t == NULL)
        cout<<"UnderFlow"<<endl;
    else if(start == t)
        deleteFirst();
    else{
        t->prev->next= t->next;
        t->next->prev = t->prev;
        delete t;
    }
}

CDLL :: ~CDLL(){
    while(start)
        deleteFirst();
}