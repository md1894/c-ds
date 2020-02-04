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

node* skipMdeleteN(node  *head, int M, int N) {
    // Write your code here
    node* t1 = head;
    node* t2 = head;
    int c1;
    int c2;
    if(head != NULL){
        while(t1 != NULL && t2 != NULL){
            c1 = 1;
            c2 = 1;
            while(c1 != M && t1 != NULL){
                t1 = t1->next;
                c1++;
            }
            if(t1 != NULL){
                t2 = t1->next;
                t1->next = NULL;
            }else{
                break;
            }
            while(c2 != N && t2 != NULL){
                node* tmp = t2;
                t2 = t2->next;
                c2++;
                delete tmp;
            }
            if(t2 != NULL){
                t2 = t2->next;
                t1->next = t2;
                t1 = t2;
            }else{
                break;
            }
        }   
    }
    return head;
}


int main()
{
    node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
