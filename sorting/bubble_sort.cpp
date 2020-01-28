#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
}

void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j+1]){
                swap(a, j, j+1);
            }
        }
    }
}

int main(){
    int a[] = {8,3,9,1,2}, n = 5;
    bubble_sort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
