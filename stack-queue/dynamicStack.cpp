#include<iostream>
#include<climits>
using namespace std;

class stack{
    
    int* data;
    int capacity;
    int nextIndex;
    
public:
    
    stack(){
        this->data = new int[5];
        this->capacity = 5;
        this->nextIndex = 0;
    }
    
    void expand(){
        int newCapacity = this->capacity*2;
        int *newArray = new int[newCapacity];
        for(int i = 0; i < this->capacity; i++){
            newArray[i] = this->data[i];
        }
        this->capacity = newCapacity;
        this->data = newArray;
    }
    
    void push(int num){
        if(this->capacity >= this->nextIndex){
            this->expand();
        }
        this->data[nextIndex] = num;
        nextIndex++;
    }
    
    int pop(){
        if(this->nextIndex == 0){
            cout<<"STACK EMPTY\r\n";
            return INT_MIN;
        }else{
            int n = this->data[nextIndex - 1];
            this->nextIndex--;
            return n;
        }
    }
    
    bool isEmpty(){
        return this->nextIndex == 0;
    }
    
    int top(){
        return this->data[nextIndex - 1];
    }
    
    void print(){
        cout<<"stack elements are\r\n";
        for(int i = 0; i < this->nextIndex ; i++){
            cout<<this->data[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  //STACK FULL
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    s.push(110);
    s.push(120);
    s.push(130);
    s.push(140);
    s.push(150);
    s.print();
    cout<<"top element is "<<s.top()<<endl;
    cout<<"poping 2 elements "<<s.pop()<<" "<<s.pop()<<endl;
    s.print();
    cout<<s.isEmpty();
    s.pop();
    s.pop();
    s.pop();
    //s.pop();  // STACK EMPTY
    return 0;
}
