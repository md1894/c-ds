/*
Reverse Stack
Send Feedback
Reverse a given Stack with the help of another empty stack.
Two stacks will be given. Out of which first contains some integers and second one is empty. 
You need to reverse the first one using second stack. Change in the given first stack itself.
Note : You don't need to print or return the stack,
just reverse the given stack and it will be printed internally.
Input format :
Line 1 : Size of Stack
Line 2 : Stack elements (separated by space)
Sample Input 1 :
4 
1 2 3 4     (4 is at top)
Sample Output 1 :
1 2 3 4    (1 is at top)
*/

#include <iostream>
#include<queue>
using namespace std;


void reverseQueue(queue<int> &q) {
	// Write your code here
    if(q.empty()){
        return;
    }else{
        int x = q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
}

int main() {
    queue<int> q;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	q.push(val);
    }
    reverseQueue(q);
    while(!q.empty()) {
    	cout << q.front() << " ";
    	q.pop();
    }
}