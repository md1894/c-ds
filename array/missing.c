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

void multipleMissing_Hashing(int* iparr,int size,int MAX){
    
    int i;
    int H[MAX];
    init(H,MAX);
    for(i = 0;i < size;i++){
        H[iparr[i]]++;
    }
    for(i = 1;i<MAX;i++){
        if(H[i] == 0){
            printf("\nMISSING ELEMENT IS %d",i);
        }
    }
}

int main(){
    int arr[5]={1,2,3,5,6};
    int arr2[6]={11,12,14,17,18,19};
    missingFirstN(arr,5);
    missingMethodTwo(arr,5);
    multipleMissing(arr2,6);
    multipleMissing_Hashing(arr,5,6);
    return 0;
}
