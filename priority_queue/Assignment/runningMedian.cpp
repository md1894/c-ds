/*
Running median
Send Feedback
You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int> > minHeap;

void adjust_pq(priority_queue<int>* max_heap, minHeap* min_heap){
    int target;
    if(max_heap->size() > min_heap->size()){
        target = max_heap->top();
        max_heap->pop();
        min_heap->push(target);
    }else{
        target = min_heap->top();
        min_heap->pop();
        max_heap->push(target);
    }
}

int pq_diff(priority_queue<int> max_heap, minHeap min_heap){
  int diff = max_heap.size() - min_heap.size();
  if(diff < 0)
      return (-1)*diff;
  else
      return diff;
}

int getMedian(priority_queue<int> max_heap, minHeap min_heap){
  int number_of_el = max_heap.size() + min_heap.size();
  bool isEven = number_of_el % 2 == 0;
  if(isEven){
    int median = (min_heap.top() + max_heap.top())/2;
    return median;
  }
  if(max_heap.size() > min_heap.size()){
    return max_heap.top();
  }else if(max_heap.size() < min_heap.size()){
    return min_heap.top();
  }
}

void findMedian(int arr[], int n){
  priority_queue<int> max_heap;
  minHeap min_heap;
  max_heap.push(arr[0]);
  cout<<arr[0]<<endl;
  for(int i = 1; i < n; i++){
      if(arr[i] > max_heap.top()){
          min_heap.push(arr[i]);
      }else{
          max_heap.push(arr[i]);
      }
      if(pq_diff(max_heap,min_heap) > 1){
        adjust_pq(&max_heap, &min_heap);
      }
      cout<<getMedian(max_heap, min_heap)<<endl;
  }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);

    delete [] arr;

}
