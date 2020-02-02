#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;
// #include "Solution.h"

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node* th = NULL;
    Node* tt = NULL;
    
    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(th == NULL && tt == NULL){
                th = head1;
                tt = head1;
                head1 = head1->next;
            }else{
                tt->next = head1;
                tt = head1;
                head1 = head1->next;
            }
        }else{
            if(th == NULL && tt == NULL){
                th = head2;
                tt = head2;
                head2 = head2->next;
            }else{
                tt->next = head2;
                tt = head2;
                head2 = head2->next;
            }
        }
    }
    if(head1 == NULL){
        tt->next = head2;
    }else{
        tt->next = head1;
    }
    
    return th;
}




int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

