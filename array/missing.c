#include<stdio.h>

int missingFirstN(int* iparr,int size){
    int sum = ((size+1)*(size+2))/2;
    int sumActual = 0;
    for(int i = 0 ;i < size; i++){
        sumActual = sumActual + iparr[i];
    }
    printf("\nthe missing element is %d",sum-sumActual);
}



void missingMethodTwo(int* iparr,int size){
    int diff = iparr[0];
    for(int i = 0;i<size;i++){
        if(diff!=iparr[i]-i){
            int miss = i+diff;
            printf("\nthe missing element is %d",miss);
            diff = iparr[i]-i;
        }
    }
}

void multipleMissing(int* iparr,int size){
    int diff = iparr[0];
    for(int i = 0;i<size;i++){
        if(diff!=iparr[i]-i){
            while(diff<iparr[i]-i){
                printf("\nthe missing element is %d",i+diff);
                diff++;
            }
        }
    }
}

void init(int* arr,int size){
    int i;
    for(i = 0;i<=size;i++){
        arr[i] = 0;
    }
}


/*
 * this method will work for both sorted and unsorted array
 * it uses hashtable , H is known as hash table
 * this is a generic method it can find single and multiple missing elements from both sorted and unsorted arrays
 */
void multipleMissing_Hashing(int* iparr,int size,int MAX){
    int low = iparr[0];
    int i;
    int H[MAX];
    init(H,MAX);
    for(i = 0;i < size;i++){
        H[iparr[i]]++;
    }
    for(i = low;i<MAX;i++){
        if(H[i] == 0){
            printf("\nMISSING ELEMENT IS %d",i);
        }
    }
}

int main(){
    int arr[5]={1,2,3,5,6};
    int arr1[5]={6,1,5,3,2};
    int arr2[6]={11,12,14,17,18,19};
    printf("\nfinding missing number :: 1,2,3,5,6 :: through missingFirstN(arr,5) \n");
    missingFirstN(arr,5);
    printf("\nfinding missing number :: 1,2,3,5,6 :: through missingMethodTwo(arr,5) \n");
    missingMethodTwo(arr,5);
    printf("\nfinding multiple missing number :: 11,12,14,17,18,19 :: through  multipleMissing(arr2,6) \n");
    multipleMissing(arr2,6);
    printf("\nfinding multiple missing number :: 11,12,14,17,18,19 :: through  multipleMissing_Hashing(arr2,6) \n");
    multipleMissing_Hashing(arr2,6,19);
    printf("\nfinding multiple missing number :: 1,2,3,5,6 :: through  multipleMissing_Hashing(arr,5,6) \n");
    multipleMissing_Hashing(arr,5,6);
    //printf("\nfinding multiple missing number :: 6,1,5,3,2 :: through  multipleMissing_Hashing(arr1,5,6) \n");
    //multipleMissing_Hashing(arr1,5,6);
    return 0;
}
