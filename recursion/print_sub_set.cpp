#include<iostream>
using namespace std;

void print_sub(int a[], int s, int op[], int m){
    if(s == 0){
        for(int i = 0; i < m; i++){
            cout<<op[i];
        }
        cout<<endl;
        return;
    }
    
    int newArray[15], i;
    for(i = 0; i < m; i++){
        newArray[i] = op[i];
    }
    newArray[i] = a[0];
    print_sub(a+1, s-1, op, m);
    print_sub(a+1, s-1, newArray, m+1);
}

void printSubsetsOfArray(int input[], int size) {
	int output_array[15];
    print_sub(input, size, output_array, 0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}