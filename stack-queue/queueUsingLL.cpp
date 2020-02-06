#include<iostream>
using namespace std;


template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};


template<typename T>
class Queue {
    
    Node<T>* head;
    Node<T>* tail;
    int size;
    
    public :
    
    
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    
    void enqueue(T data) {
        if(head == NULL){
            this->head = new Node<T>(data);
            this->tail = head;
        }else{
            Node<T>* nw = new Node<T>(data);
            this->tail->next = nw;
            tail = nw;
        }
        this->size++;
    }
    
    int getSize() {
        return this->size;
    }
    
    bool isEmpty() {
        return this->size == 0;
    }
    
    T dequeue() {
        // Return 0 if queue is empty
        if(this->size == 0){
            return 0;
        }else{
            Node<T>* nw = this->head;
            head = head->next;
            this->size--;
            return nw->data;
        }
    }
    
    T front()  {
        // Return 0 if queue is empty
        if(this->size == 0){
            return 0;
        }else{
            return this->head->data;
        }
    }
};

int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
    
}

