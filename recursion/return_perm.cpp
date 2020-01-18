#include <string>
#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0)
        return 1;
    else
        return n*fact(n-1);
}

void add_char(int step, char c, int end, string output[]){
    int k = 0;
    for(int i = 0; i < end; i = i + step){
        for(int j = i; j < i + step; j++){
            output[j] = output[j].substr(0,k) + c + output[j].substr(k, output[j].length());
        }
        k++;
    }
}

void create_copy(int start, int end, string output[]){
    int step = start;
    for(int i = start; i < end; i++){
        output[i] = output[i-start];
    }
}   



int returnPermutations(string input, string output[]){
   	//base case
    if(input.length() == 1){
        output[0] = input;
        return 1;
    }
    int r = returnPermutations(input.substr(1), output);
    int start = r;
    int end = start*input.length();
    create_copy(start, end, output);
    add_char(r, input[0], end, output);
    return end;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}