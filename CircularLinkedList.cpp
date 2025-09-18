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

CLL :: CLL(CLL &list){
    node *t;
    if(list.last==NULL)
        last=NULL;
    else{
        t=list.last->next;
        while (t!=list.last){
            insertAtLast(t->item);
            t =t->next;
        }
        insertAtLast(t->item);
    }
}

CLL& CLL:: operator=(CLL& list){
    while(last)
        deleteFirst();
    node *t;
    if(list.last==NULL)
        last=NULL;
    else{
        t=list.last->next;
        while (t!=list.last){
            insertAtLast(t->item);
            t =t->next;
        }
        insertAtLast(t->item);
    }
    return *this;
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

node* CLL :: search(int data){
    if(last==NULL)
        return NULL;
    if(last->item==data)
        return last;
    node* t = last->next; // accessed to first index
    while (t != last){
        if(t->item == data)
            return t;
        t=t->next;
    }
    return NULL;
}

void CLL :: insertAfter(node* t , int data){
    node* n =new node;
    if(t==last)
        insertAtLast(data);
    else if(t){
        n->item = data;
        n->next = t->next;
        t->next = n;
    } 
}

void CLL :: deleteFirst(){
    node* r;
    if(last){
        r = last->next;
        last = r->next;
        if(last == r)
            last = NULL;
        delete r;
    }
}

void CLL::deleteLast(){
    node* r, *t;
    if(last){
        r = last;
        if(r->next==r)
            last = NULL;
        else{
            t = last->next;
            while(t->next!=last)
                t=t->next;
            t->next = last->next;
            last = t;
        }
        delete r;
    }
}

void CLL:: deleteNode(node* t){
    node *r;
    if(t!=NULL){
        if(t==last)
            deleteLast();
        else if(t==last->next)
            deleteFirst();
        else{
            r=last->next;
            while(r->next!=t)
                r=r->next;
            r->next=t->next;
            delete t;
        }
    }
}

CLL :: ~CLL(){
    while(last)
        deleteFirst();
}
