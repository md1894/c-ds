/*
Reverse Word Wise
Send Feedback
Reverse the given string word wise. That is, the last word in given string should come at 1st place, last second word at 2nd place and so on. Individual words should remain as it is.
Sample Input:

Welcome to Coding Ninjas

Sample Output:

Ninjas Coding to Welcome


*/

#include <iostream>
using namespace std;


// input - given string
// You need to update in the given string itself. No need to print or return anything


void swap(char a[],int i, int j){
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void reverseStringWordWise(char input[]) {
    int start = 0,end = 0,length,j;
    for(int i = 0; input[i] != '\0'; i++){
        end++;
    }
    end--;
    while(start<end){
        swap(input,start,end);
        start++;
        end--;
    }
    j = 0;
    while(input[j] != '\0'){
        start = j;
        if(input[j] == 32)
            start++;
        while(input[j+1] != 32 && input[j+1] != '\0'){
            j++;
        }
        end = j;
        while(start<end){
            swap(input,start,end);
            start++;
            end--;
        }
        j++;
    }
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
