#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void selection_sort(int a[], int n){
    int j,k;
    for(int i = 0; i < n - 1; i++){
        for(j=k=i; j < n; j++){
            if(a[j]<a[k]){
                k = j;
            }
        }
        swap(a,i,k);
    }
}

int main(){
    int a[] = {8,3,9,1,2}, n = 5;
    selection_sort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}