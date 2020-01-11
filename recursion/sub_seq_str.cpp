#include<iostream>
using namespace std;

int p(int i, int j){
    if(j == 0)
        return 1;
    return i*p(i,j-1);
}

int subseq(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }

    int smallOutputSize = subseq(input.substr(1), output);
    for(int i = 0; i < smallOutputSize; i++){
        output[i + smallOutputSize] = input[0] + output[i];
    }

    return 2*smallOutputSize;
}

int main(){
    string a;
    int size;
    cin>>a;
    size = p(2, a.size());
    string* output = new string[size];
    subseq(a,output);
    for(int i = 0; i < size; i++){
        cout<<output[i]<<endl;
    }
    return 0;     
}