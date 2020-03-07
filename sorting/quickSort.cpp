#include<iostream>
using namespace std;

void swap(int* n1, int* n2){
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int partition(int a[], int start, int end){
  int pivot = a[end];
  int pIndex = start;
  for(int i = start; i < end; i++){
    if(a[i] <= pivot){
      swap(&a[i], &a[pIndex]);
      pIndex++;
    }
  }
  swap(&a[pIndex], &a[end]);
  return pIndex;
}

void quickSort(int a[], int start, int end){
  if(start < end){
    int partitionIndex = partition(a, start, end);
    quickSort(a, start, partitionIndex - 1);
    quickSort(a, partitionIndex + 1, end);
  }
}

int main(){
  int a[] = {7,2,1,6,8,5,3,4};
  quickSort(a,0,7);
  cout<<"Sorted"<<endl;
  for(int i = 0; i < 8; i++){
    cout<<a[i]<<endl;
  }
  return 0;
}