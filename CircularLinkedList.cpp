#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class CLL{
    private:
        node *start;
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