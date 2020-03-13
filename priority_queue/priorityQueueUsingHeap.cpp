#include<vector>
#include<climits>
#include<iostream>
using namespace std;

/*
 * store complete binary tree in the form of vector
 * so we will access nodes and their child by deriving
 * relation from their index;
 *
 * i(Node Index) ---->> 2i+1(left child) , 2i+2(right child)
 * PI(parent index) --->> ( CI(child index) - 1 )/2
 */

class priorityQueue{
    vector<int> pq;

public:
    priorityQueue(){
    }

    int getSize(){
        return pq.size();
    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    static void swap(int* i1, int* i2){
        int temp = *i1;
        *i1 = *i2;
        *i2 = temp;
    }

    void insert(int el){
        pq.push_back(el);
        int childIndex = pq.size() - 1;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            if(pq[childIndex] < pq[parentIndex]){
                swap(&pq[childIndex], &pq[parentIndex]);
            }else
                break;
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        int leftChildIndex = (2*parentIndex) + 1;
        int rightChildIndex = (2*parentIndex) + 2;
        while(leftChildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]){
              minIndex = leftChildIndex;
            }
            if(rightChildIndex < pq.size() &&
                pq[minIndex] > pq[rightChildIndex]){
                  minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
              break;
            }
            swap(&pq[minIndex], &pq[parentIndex]);
            parentIndex = minIndex;
        }
        return ans;
    }

    int getMin(){
        if(isEmpty()){
            return INT_MIN;
        }else{
            return pq[0];
        }
    }
};


int main() {
    priorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
