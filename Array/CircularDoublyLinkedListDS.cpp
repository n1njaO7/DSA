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

DLL::DLL(){
    start = NULL;
}