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
