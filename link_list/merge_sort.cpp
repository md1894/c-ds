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
    
    node* h2 = split(head);
    
    
}