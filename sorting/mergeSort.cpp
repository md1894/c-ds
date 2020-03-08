#include<iostream>
using namespace std;


void merge(int a[], int l, int m, int h){
		int temp[h + 1];
		int left = l;
		int leftEnd = m;
		int right = m + 1;
		int rightEnd = h;
		int k = l;
		/*
		 * This is the case when there are elements present in
		 * both the small arrays
		 * This loop will run until one of the array got emptied
		 */
		while(left <= leftEnd && right <= rightEnd){
				if(a[left] < a[right]){
					temp[k++] = a[left++];
				}else{
					temp[k++] = a[right++];
				}
		}
		/*
		 * if there are elements in left array;
		 */
		for(;left<=leftEnd;left++){
			temp[k++] = a[left];
		}
		/*
		 * if there are elements in right array;
		 */
		for(;right <= rightEnd; right++){
			temp[k++] = a[right];
		}
		/*
		 * copy the elements back from temp array to the original array
		 */
		for(int i = l; i < h + 1; i++){
			a[i] = temp[i];
		}

}

void mergeSort(int a[], int start, int end){
	  /*
		 * This condition will check that
		 * Size of Array must be greater than 2
		 */
		if(start < end){
				int mid = (start+end)/2;
				mergeSort(a, start, mid);
				mergeSort(a, mid + 1, end);
				merge(a, start, mid, end);
		}
}

int main(){
		int a[] = {2,4,1,6,8,5,3,7};
		int n = 8;
		mergeSort(a,0,7);
		cout<<"After mergeSort"<<endl;
		for(int i = 0; i < 8; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return 0;
}
