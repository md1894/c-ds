/*
Check redundant brackets
Send Feedback
Given a string mathematical expression, return true if redundant brackets are present in the expression. 
Brackets are redundant if there is nothing inside the bracket or more than one pair of brackets are present.
Assume the given string expression is balanced and contains only one type of bracket i.e. ().
Note: You will not get partial score for this problem. You will get marks only if all test cases are passed.
Input Format :
String s (Expression)
Output Format :
true or false
Sample Input 1:
((a + b)) 
Sample Output 1:
true
Sample Input 2:
(a+b) 
Sample Output 2:
false
*/

#include <iostream>
#include<stack>
using namespace std;


bool checkRedundantBrackets(char *input) {
	// Write your code here
    int count;
    bool what;
    stack<char> st;
    for(int i = 0; input[i] != 0; i++){
        if(input[i] != ')'){
            st.push(input[i]);
        }else{
            count = 0;
            char n = 0;
            while(n != '('){
                n = st.top();
                st.pop();
                if(n!='(')
                    count++;
            }
            if(count > 0){
                what = false;
            }else{
                what = true;
                break;
            }
        }
    }
    return what;
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}