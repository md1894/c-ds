/*
Even after Odd LinkedList
Send Feedback
Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
Note: Input and Output has already managed for you. You don't need to print the elements, instead return the head of updated LL.
Input format:
Linked list elements (separated by space and terminated by -1)
Output format:
Print the elements of updated Linked list. 
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 
Sample Input 2 :
1 11 3 6 8 0 9 -1
Sample Output 2 :
1 11 3 9 6 8 0
*/
#include <iostream>
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


node* arrange_LinkedList(node* head)
{
    //write your code here
    node* even_head = NULL;
    node* even_tail = NULL;
    node* odd_head = NULL;
    node* odd_tail = NULL;
    node* temp = head;
    if(head != NULL){ 
        while(temp != NULL){
            if(temp->data % 2 == 0){
                if(even_head == NULL){
                    even_tail = temp;
                    even_head = temp;   
                }else{
                    even_tail->next = temp;
                    even_tail = temp;
                }
            }else{
                if(odd_head == NULL){
                    odd_tail = temp;
                    odd_head = temp;   
                }else{
                    odd_tail->next = temp;
                    odd_tail = temp;
                }
            }
            temp = temp->next;
        }
        if(odd_tail != NULL){
            odd_tail->next = even_head;
            head = odd_head;
        }else{
            head = even_head;
        }
        if(even_tail != NULL){
            even_tail->next = NULL;
        }
    }
    return head;
}


int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}