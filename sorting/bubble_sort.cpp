#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
}

void bubble_sort(int a[], int n){
    /*
     * we have to preform one pass less because:
     * when it comes to compare a[end-1] and a[end]
     * then we will not goto index 'end', therefore we travell
     * 'n-1' passes
     */
    for(int i = 0; i < n - 1; i++)
    {  
        for(int j = 0; j < n - 1 - i; j++)
	{
            if(a[j] > a[j+1])
	    {
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
