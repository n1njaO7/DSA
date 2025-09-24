#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class Stack{
    private:
        node *start;
    public:
        Stack();
        Stack(Stack&);
        Stack& operator=(Stack&);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~Stack(); 
};