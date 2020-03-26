/*
kReverse
Send Feedback
Implement kReverse( int k ) in a linked list i.e. you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well. If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : k

Sample Input 1 :
1 2 3 4 5 6 7 8 9 10 -1
4
Sample Output 1 :
4 3 2 1 8 7 6 5 10 9
Sample Input 2 :
1 2 3 4 5 -1
2
Sample Output 2 :
2 1 4 3 5 
Sample Input 3 :
1 2 3 4 5 6 7 -1
3
Sample Output 3 :
3 2 1 6 5 4 7
*/

#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
// #include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* reverse(node* head){
    if(head->next == NULL){
        return new node(head->data);
    }else{
        node* nwHead = reverse(head->next);
        node* nwTail = new node(head->data);
        node* temp = nwHead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nwTail;
        return nwHead;
    }
}


node* kReverse(node*head,int n)
{
    //write your code here
    if(head != NULL){
        if(head->next == NULL){
            return new node(head->data);
        }else{
            node* temp = head;
            int c1 = 1;
            while(c1 != n){
                c1++;
                if(temp != NULL){
                     temp = temp->next;   
                }else{
                    break;
                }
            }
            node* H = NULL;
            if(temp != NULL){
                 H = temp->next;
                 temp->next = NULL;
            }
            node* t3 = kReverse(H,n);
            node* t2 = reverse(head);
            c1 = 1;
            node* tail = t2;
            while(c1 != n){
                c1++;
                if(tail != NULL){
                     tail = tail->next;   
                }
            }
            if(tail != NULL){
                 tail->next = t3;   
            }
            return t2;
        }
    }else{
        return head;
    }
}


int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
