/*
Merge K sorted arrays
Send Feedback
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.
Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
Sample Input 1 :
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0
Sample Output 1 :
0 1 2 5 6 9 45 78 90 100 234
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class triplet{
  public:
    int element;
    int arrayIndex;
    int elementIndex;

    triplet(int element, int arrayIndex, int elementIndex){
        this->element = element;
        this->arrayIndex = arrayIndex;
        this->elementIndex = elementIndex;
    }
};

class compare_fn{
  public:
    bool operator()(triplet &t1, triplet &t2){
      return t1.element > t2.element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    priority_queue<triplet, vector<triplet>, compare_fn> pq;
    vector<int> v;
    int el,array_index,element_index;
    for(int i = 0; i < input.size(); i++){
        triplet t(input[i][0], i, 0);
        pq.push(t);
    }
}


int main() {

	int k;
	cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }


	vector<int> output = mergeKSortedArrays(input);

	for(int i = 0; i < output.size(); i++)
		cout << output[i] << " ";

	return 0;
}
