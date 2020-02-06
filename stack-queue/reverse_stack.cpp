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