#include<iostream>
#include<stack>
using namespace std;

int len(char* a){
	if(*a == 0)
		return 0;
	else
		return 1 + len(a+1);
}

int countBracketReversals(char* input){
	stack<char> st;
	int l = len(input);
	int count;
	if(l % 2 == 0){
		for(int i = 0; input[i] != 0; i++){
			if(input[i] == '{')
				st.push(input[i]);
			else if(input[i] == '}' && !st.empty()){
				if(st.top() == '{')
			       		st.pop();
				else
					st.push(input[i]);

			}
			else
				st.push(input[i]);	
		}
		count = 0;
		while(!st.empty()){
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();
			if(c1 == c2)
				count++;
			else
				count += 2;
		}
		return count;
	}else{
		return -1;
	}
}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
    return 0;
}
