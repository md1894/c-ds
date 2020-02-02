#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};


int len(node* head){
    if(head == NULL)
        return 0;
    else
        return 1 + len(head->next);
}

node* reverse(node* head){
    if(head->next == NULL){
        return new node(head->data);
    }else{
        node* nw = reverse(head->next);
        node* temp = new node(head->data);
        nw->next = temp;
        temp->next = NULL;
        return nw;
    }
}

bool check_palindrome(node* head)
{
    node* temp = head;
    node* sec = NULL;
    int mid = len(temp)/2;
    int count = 0;
    bool is_pal = false;
    while(count < mid){
        count++;
        temp = temp->next;
    }
    sec = temp;
    temp = head;
    sec = reverse(sec);
    count = 0;
    while(sec != NULL && temp != NULL && count <=mid){
        count++;
        if(sec->data == temp->data){
            is_pal = true;
        }else{
            is_pal = false;
            break;
        }
    }
    return is_pal;
}



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
int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true";
    else 
        cout << "false";
    return 0;
}