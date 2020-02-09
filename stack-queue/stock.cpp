#include<iostream>
#include<stack>
using namespace std;

int* stockSpan(int *price, int size) {
	// Write your code here
    int* span = new int[size];
    stack<int> st;
    st.push(0);
    span[0] = 1;
    int n;
    for(int i = 1; i < size; i++){
        while(!st.empty()){
            n = st.top();
            if(price[n] < price[i]){
                st.pop();
            }else{
                break;
            }
        }
        if(st.empty()){
            span[i] = i + 1;
        }else{
            span[i] = i - n;
        }
        st.push(i);
    }
    
    return span;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}