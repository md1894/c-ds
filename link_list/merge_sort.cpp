/*
Code: Merge Sort
Send Feedback
Sort a given linked list using Merge Sort.
You don't need to print the elements, just sort the elements and return the head of updated LL.
Input format :
Linked list elements (separated by space and terminated by -1)
Output format :
Updated LL elements (separated by space)
Constraints :
1 <= Length of LL <= 1000
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
*/

//merge sort recursive
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

// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/

node* mergeTwoLLs(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    node* th = NULL;
    node* tt = NULL;
    
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

node* split(node* head){
    // Write your code here
    node* slow = head;
    node* fast = NULL;
    if(slow->next != NULL)
        fast = slow->next;
    if(fast != NULL){
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
    }
    return slow;
}

node* mergeSort(node *head) {
    //write your code here
    if(head->next == NULL)
        return head;
    
    node* h1 = split(head);
    node* temp = h1;
    h1 = h1->next;
    temp->next = NULL;
    node* h2 = head;
    h1 = mergeSort(h1);
    h2 = mergeSort(h2);
    node* h3 = mergeTwoLLs(h1,h2);
    return h3;
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
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}
