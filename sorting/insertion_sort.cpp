#include<iostream>
using namespace std;


void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int target = a[i];
        int j = i - 1;
        while(j > -1 && a[j] > target){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = target;
    }
}

int main(){
    int a[] = {8,3,9,1,2}, n = 5;
    insertion_sort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
