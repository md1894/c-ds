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

template <typename T>
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack
    
    public :
    
    Stack() {
        this->head = NULL;
        this->size = 0;
    }
    
    int getSize() {
        return this->size;
    }
    
    bool isEmpty() {
        return this->size == 0;
    }
    
    void push(T element) {
        if(this->head == NULL){
            this->head = new Node<T>(element);
            this->size++;
        }else{
            Node<T>* newNode = new Node<T>(element);
            newNode->next = head;
            head = newNode;
            this->size++;
        }
    }
    
    T pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(this->size == 0){
            return 0;
        }else{
            Node<T>* tmp = head;
            T n = tmp->data;
            head = head->next;
            delete tmp;
            this->size--;
            return n;
        }
    }
    
    T top() {
        // Return 0 if stack is empty. Don't display any other message
        if(this->size == 0){
            return 0;
        }else{
            return this->head->data;
        }
    }
    
  
    
};



int main() {
        
    Stack<int> st;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            st.push(input);
        }
        else if(choice == 2) {
            int ans = st.pop();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = st.top();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << st.getSize() << endl;
        }
        else if(choice == 5) {
    if(st.isEmpty()){
                cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
        }
        cin >> choice;
    }
    
}