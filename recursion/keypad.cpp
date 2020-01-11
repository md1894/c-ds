#include<iostream>
using namespace std;
#include "key.h"


void create_copy(string str[], int n, int size){
    for(int i = size; i < size*n; i++){
        str[i] = str[i - size];
    }
}

int keypad(int num, string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    int smallOutputSize = keypad(num/10, output);
    string currentCharSet = char_set[num % 10];
    int currentCharSetSize = char_size[num % 10];
    create_copy(output, currentCharSetSize, smallOutputSize);
    for(int i = 0; i < currentCharSetSize; i++){
        int step = i*smallOutputSize;
        for(int j = step; j < (i+1)*smallOutputSize; j++){
            output[j] += currentCharSet[i];
        }
    }
    return currentCharSetSize*smallOutputSize;
}

int main(){
    int n, size = 1;
    string a[1000];
    cin>>n;
    // for(int i = n ; i > 0 ; i = i/10){
    //     int e = i % 10;
    //     size *= char_size[e];
    // }
    // cout<<endl<<"size is "<<size<<endl;
    int res = keypad(n, a);
    for(int i = 0; i < res; i++){
        cout<<a[i]<<endl;
    }
    return 0;
}