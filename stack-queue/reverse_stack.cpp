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
#include<stack>
using namespace std;


void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
    if(input.size() == 1){
        return;
    }else{
        int x = input.top();
        input.pop();
        reverseStack(input, extra);
        while(!input.empty()){
            int n = input.top();
            input.pop();
            extra.push(n);
        }
        extra.push(x);
        while(!extra.empty()){
            int n = extra.top();
            extra.pop();
            input.push(n);
        }
    }
}


int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}