#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
    int item;
    node* next;
};

class Stack{
    private:
        node *top;
    public:
        Stack();
        Stack(Stack&);
        Stack& operator=(Stack&);
        void push(int);
        int peek(int);
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int); 
        void deleteFirst();   
        void deleteLast();   
        void deleteNode(node*);  
        ~Stack(); 
};

Stack::Stack(){
    top = NULL;
}

void Stack :: push(int data){
    node *n = new node;
    n->item=data;
    n->next=top;
    top=n;
} 
