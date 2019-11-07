#include<stdio.h>

void k_sum(int* iparr,int size,int k){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j < size;j++){
            if(iparr[i] +iparr[j] == k){
                printf("\nSUM OF %d + %d = %d\n",iparr[i],iparr[j],k);
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

int getmax(int* arr,int size){
    int i;
    int j;
    int max = arr[0];
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[j]>max){
                max = arr[j];
            }
        }
    }
    return max;
}


void sum_hashing(int* iparr,int size,int k){
    int max = getmax(iparr,size),i;
    int H[max+1];
    init(H,max+1);
    for(i=0;i<size;i++){
        if(H[k-iparr[i]]!=0){
            printf("\n %d + %d = %d",iparr[i],k-iparr[i],k);
        }
        H[iparr[i]]++;
    }
}


int main(){
    int arr[7]={11,6,9,2,7,4,1};
    k_sum(arr,7,10);
    sum_hashing(arr,7,10);
    return 0;
}
