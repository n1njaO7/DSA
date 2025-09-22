#include <iostream>
using namespace std;

class DynamicArray
{
    private :
        int capacity;
        int lastIndex;
        int *ptr;

    protected :
        void doubleArray();
        void halfArray();
    
    public:
        DynamicArray();
        DynamicArray(DynamicArray&);
        DynamicArray &operator = (DynamicArray&); 
        void createDynamicArray(int);
        void insert(int,int);
        void append(int);
        int getItem(int);
        bool isEmpty();
        bool isFull();
        void del(int);
        void edit(int,int);
        int count();
        int getCapacity();
        ~DynamicArray();
};

DynamicArray :: DynamicArray(){
    ptr = NULL;
}

DynamicArray :: DynamicArray (DynamicArray &arr){
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for(int i = 0; i<=lastIndex ; i++){
        ptr[i] = arr.ptr[i];
    }
}

DynamicArray& DynamicArray :: operator=(DynamicArray &arr){
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

void DynamicArray :: doubleArray(){
    int *temp;
    temp = new int [capacity*2];
    for (int i = 0 ; i<lastIndex ; i++)
        temp[i] = ptr[i];
    delete []ptr;
    ptr = temp;
    capacity = capacity*2;
}

void DynamicArray :: halfArray(){
    int *temp;
    temp = new int[capacity/2];
    for (int i = 0 ; i<=lastIndex; i++)
        temp[i] = ptr[i];
    delete []ptr;
    ptr = temp;
    capacity = capacity/2;
}

void DynamicArray :: createDynamicArray(int cap){
    capacity = cap;
    lastIndex = -1;
    if(ptr!= NULL){
        delete []ptr;
    }
    ptr = new int[capacity];
}

void DynamicArray :: append(int data){
    if(isFull()){
        doubleArray();
    }
    lastIndex++;
    ptr[lastIndex] = data; 

}


bool DynamicArray :: isFull(){
    return lastIndex == capacity-1;
}

bool DynamicArray :: isEmpty(){
    return lastIndex == -1;
}

void DynamicArray :: insert(int data , int index){
    try{
        if(index<0 || index > lastIndex+1)
            throw 1;
        else if(isFull)
            doubleArray();
        
        for(int i=lastIndex ; i>=index;i--)
            ptr[i+1] = ptr[i];
        ptr[index] = data;
        lastIndex++; 
    }
    catch(int e){
        if(e==1){
            cout<<"\nINvalid Index";
        }
    }       
}

int DynamicArray :: getItem(int index){
    try{
        if (index<0 || index> lastIndex)
            throw 1;
        return ptr[index];
    
    }
    catch(int e){
        if(e ==1)
            cout<<"\nInvalid index or Empty DynamicArray";
    }
    return -1;
}

int DynamicArray :: getCapacity(){
    return capacity;
}

int DynamicArray :: count(){
    return lastIndex+1;
}

void DynamicArray :: edit(int index , int data ){
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

void DynamicArray :: del(int index){
    try{ 
        if(index<0 || index> lastIndex)
            throw 1;
        
        for(int i = index ; i <lastIndex; i++){
            ptr[i] = ptr[i+1]; 
        }
        lastIndex --;
        if(capacity>1 && lastIndex+1 <= capacity/2)
            halfArray();
    }
    catch(int e){
        if(e==1)
            cout<<"\nInvalid Index";
    }
}

DynamicArray :: ~DynamicArray(){
    delete []ptr;
}
