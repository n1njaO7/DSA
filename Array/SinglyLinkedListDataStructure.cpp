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
        void insertAtStart(int);    
        void insertAtLast(int);    
        void insertAfter(node*,int);
        node* search(int);    
};

SLL::SLL(){
    start = NULL;
}
void SLL :: insertAtStart(int data){
    
}