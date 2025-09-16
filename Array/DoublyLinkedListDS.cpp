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