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
     * when we sort the second last element , we know that the last element is the only element
     * and if there is only one element rest are in sorted position , then that element is also sorted
     */
    for(int i = 0; i < n - 1; i++)
    {  /*
	* Here Comparions will reduced by one , every iteration of 'i' loop (Outer)
    	*/
        for(int j = 0; j < n - 1 - i; j++)
	{
            if(a[j] > a[j+1])
	    {
                swap(a, j, j+1);
            }
        }
    }
}

void AdaptiveBubbleSort(int a[], int n){
	int flag;
	for(int i = 0; i < n - 1; i++){
		flag = 0;
		for(int j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j+1]){
				swap(a,j,j+1);
				flag = 1;
			}
		}
		if(flag == 0)
			break;
	}
}

int main(){
    int a[] = {8,3,9,1,2}, n = 5;
    AdaptiveBubbleSort(a,n);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}















