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



/*
 * this function will find pair of element whose sum is k , for a sorted array
 */
void sum_sorted(int* iparr,int size,int k){
    int i = 0;
    int j = size-1;
    while(i<j){
        if(iparr[i]+iparr[j] == k){
            printf("\n %d + %d = %d",iparr[i],iparr[j],k);
            i++;
            j--;
        }else if(iparr[i]+iparr[j] >k){
            j--;
        }else{
            i++;
        }
    }
}


int main(){
    int arr[7]={11,6,9,2,7,4,1};
    int arr1[7] = {1,2,4,6,7,9,11};
    printf("\n---------------------------------------------------------\n");
    k_sum(arr,7,10);
    printf("\n---------------------------------------------------------\n");
    sum_hashing(arr,7,10);
    printf("\n---------------------------------------------------------\n");
    sum_sorted(arr1,7,10);
    printf("\n---------------------------------------------------------\n");
    return 0;
}
