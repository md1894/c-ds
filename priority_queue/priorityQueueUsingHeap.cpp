#include<vector>
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
    
    
    
    int getMin(){
        if(isEmpty()){
            return 0;
        }else{
            return pq[0];
        }
    }
};
