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