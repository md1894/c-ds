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

int len(node* head){
    if(head == NULL){
        return 0;
    }else{
        return 1 + len(head->next);
    }
}

void swap(node* i, node* j){
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}

node* bubble_sort_LinkedList_itr(node* head)
{
    if(head != NULL){
        int l = len(head);
        node* temp = head;
        for(int i = 0; i < l - 1; i++){
            int j = l - i - 1;
            node* first = temp;
            node* second = temp->next;
            for(int k = 0; k < j; k++){
                if(first->data > second->data){
                    swap(first,second);
                }
                first = first->next;
                second = second->next;
            }
            temp = head;
        }
    }
    return head;
}


int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}
