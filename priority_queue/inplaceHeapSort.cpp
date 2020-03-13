/*
Code : In-place heap sort
Send Feedback
Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :
Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space
Output Format :
Array elements after sorting
Constraints :
1 <= n <= 10^6
Sample Input:
6
2 6 8 5 4 3
Sample Output:
8 6 5 4 3 2
*/
#include <iostream>
using namespace std;

void swap(int* i1, int* i2){
    int temp = *i1;
    *i1 = *i2;
    *i2 = temp;
}

void inplaceHeapSort(int pq[], int n){
      /*
      create Heap uisng array
      up-heapify
      */
      for(int i = 1; i < n; i++){
        int childIndex = i;
        while(childIndex > 0){
          int parentIndex = (childIndex - 1)/2;
          if(pq[parentIndex] > pq[childIndex]){
            swap(&pq[childIndex], &pq[parentIndex]);
          }else
            break;

          childIndex = parentIndex;
        }
      }
      /*
      write removeMin() logic for n - 1 elements starting
      down-heapify
      */
      int size = n;
      while(size > 1){
        swap(&pq[0], &pq[size - 1]);
        size--;
        int parentIndex = 0;
        int leftChildIndex = (parentIndex*2) + 1;
        int rightChildIndex = (parentIndex*2) + 2;
        while(leftChildIndex < size){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]){
              minIndex = leftChildIndex;
            }
            if(rightChildIndex < size && pq[minIndex] > pq[rightChildIndex]){
              minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
              break;
            }
            swap(&pq[parentIndex], &pq[minIndex]);
            parentIndex = minIndex;
            leftChildIndex = (parentIndex*2) + 1;
            rightChildIndex = (parentIndex*2) + 2;
        }
      }
}



int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];

	for(int i = 0; i < size; i++)
		cin >> input[i];

	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";

	return 0;
}
