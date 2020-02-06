#include <iostream>
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



bool checkBalanced(char *exp) {
	// Write your code here
    
    Stack<char> st;
    bool isBalanced = true;
    for(int i = 0; exp[i] != 0; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            st.push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            char tmp = st.pop();
            tmp = (exp[i] == ')')?tmp+1:tmp+2;
            if(tmp != exp[i]){
                isBalanced = false;
                break;
            }
        }
    }
    if(st.isEmpty() && isBalanced){
        return true;
    }else{
        return false;
    }
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
