#include <iostream>
using namespace std;

class Array
{
    private :
        int capacity;
        int lastIndex;
        int *ptr;
    public:
        Array();
        Array(Array&);
        Array &operator = (Array&); 
        void createArray(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int,int);
        int count();
        int getCapacity();
        ~Array();
};

Array :: Array(){
    ptr = NULL;
}

Array :: Array (Array &arr){
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for(int i = 0; i<=lastIndex ; i++){
        ptr[i] = arr.ptr[i];
    }
}

Array& Array :: operator=(Array &arr){
    if(this == &arr)
        return *this;
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if(ptr != NULL)
        delete []ptr;
    ptr = new int[capacity];
    for(int i = 0; i<=lastIndex ; i++){
        ptr[i] = arr.ptr[i];
    }
    return (*this);
}

void Array :: createArray(int cap){
    capacity = cap;
    lastIndex = -1;
    if(ptr!= NULL){
        delete []ptr;
    }
    ptr = new int[capacity];
}

void Array :: append(int data){
    if(!isFull()){
        lastIndex++;
        ptr[lastIndex] = data; 
    }
    else{
        cout<<"\nError : overflow , append can't be performed "<<endl;
    }
}

bool Array :: isFull(){
    return lastIndex == capacity-1;
}

bool Array :: isEmpty(){
    return lastIndex == -1;
}

void Array :: insert(int data , int index){
    try{
        if(index<0 || index > lastIndex+1)
            throw 1;
        else if(isFull)
            throw 2;
        
        for(int i=lastIndex ; i>=index;i--)
            ptr[i+1] = ptr[i];
        ptr[index] = data;
        lastIndex++; 
    }
    catch(int e){
        if(e==1){
            cout<<"\nINvalid Index";
        }
        else if(e==2){
            cout<<"\nOverFlow";
        }
    }       
}



int Array :: getItem(int index){
    try{
        if (index<0 || index> lastIndex)
            throw 1;
        return ptr[index];
    
    }
    catch(int e){
        if(e ==1)
            cout<<"\nInvalid index or Empty Array";
    }
    return -1;
}

int Array :: getCapacity(){
    return capacity;
}

int Array :: count(){
    return lastIndex+1;
}

void Array :: edit(int index , int data ){
    try{
        if( index <0 || index > lastIndex)
            throw 1;
        
        ptr[index] = data;
        
    }
    catch (int e){
        if(e==1)
            cout<< "\nInavlid Index";
    }
}

void Array :: del(int index){
    try{ 
        if(index<0 || index> lastIndex)
            throw 1;
        
        for(int i = index ; i <lastIndex; i++){
            ptr[i] = ptr[i+1]; 
        }
        lastIndex --;
    }
    catch(int e){
        if(e==1)
            cout<<"\nInvalid Index";
    }
}

Array :: ~Array(){
    delete []ptr;
}