#include <iostream>
using namespace std;

class Stack
{
    private :
        int capacity;
        int top;
        int *ptr;
    public:
        Stack();
        Stack(Stack&);
        Stack &operator = (Stack&); 
        void createStack(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
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

