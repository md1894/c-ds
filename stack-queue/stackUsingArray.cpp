#include<iostream>
#include<climits>
using namespace std;

class stack{
    
    int *data;
    int capacity;
    int nextIndex;
    
public:
    
    stack(int n){
        this->data = new int[n];
        this->capacity = n;
        this->nextIndex = 0;
    }
    
    void push(int num){
        if(this->nextIndex < this->capacity){
            this->data[nextIndex] = num;
            nextIndex++;
        }else{
            cout<<"STACK IS FULL\r\n";
        }
    }
    
    int pop(){
        if(this->nextIndex == 0){
            cout<<"STACK IS EMPTY\r\n";
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
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    //s.push(50);  //STACK FULL
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
