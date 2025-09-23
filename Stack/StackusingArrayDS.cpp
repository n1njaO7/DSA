#include <iostream>
#include<stdio.h>
using namespace std;
#define STACK_IS_EMPTY 1

class Stack
{
    private :
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(int);
        Stack(Stack&);
        Stack &operator = (Stack&); 
        void createStack(int);
        void push(int);
        int peek();
        void pop(int);
        void insert(int,int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void edit(int,int);
        int count();
        int getCapacity();
        ~Stack();
};

Stack :: Stack(){
    capacity = 0;
    top = -1;
    ptr=NULL;
}

Stack :: Stack(int cap){
    capacity = cap;
    top = -1;
    ptr=new int[cap];
}

void Stack :: createStack(int cap){
    if(ptr!=NULL)
        delete ptr;
    capacity = cap;
    top = -1;
    ptr = new int[capacity];
}

bool Stack :: isFull(){
    return top == capacity-1;
}  

void Stack :: push(int data){
    if(isFull())
        cout<<"\nStack Overflow";
    else{
        top++;
        ptr[top]=data;
    }
}

int Stack :: peek(){
    if(isEmpty())
        throw STACK_IS_EMPTY;
    return ptr[top];
}

bool Stack :: isEmpty(){
    return top == -1; 
}

void Stack :: pop(int data){
    if(isEmpty())
        cout<<"\nStack Overflow";
    else{
        top--;
    }
}