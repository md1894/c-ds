#include<stdio.h>

void duplicate(int* iparr,int size){
    int lastDuplicate = 0;
    int i;
    for(i=0;i<size-2;i++){
        if(iparr[i] == iparr[i+1] && iparr[i] != lastDuplicate){
            printf("%d\t",iparr[i]);
            lastDuplicate = iparr[i];
        }
    }
}

void duplicateVTwo(int* iparr,int size){
    int i;
    printf("\n");
    for(i=0;i<size-2;i++){
        if(iparr[i] == iparr[i+1]){
            int j = i + 1;
            while(iparr[i] == iparr[j]){
                j++;
            }
            printf("duplicate element %d repeated for %d timies\n",iparr[i],j-i);
            i = j;
        }
    }
}

void init(int* arr,int size){
    int i;
    for(i=0;i<size;i++){
        arr[i]=0;
    }
}

void duplicate_hashing(int* iparr,int size){
    int max = iparr[size-1] + 1;
    int H[max];
    init(H,max);
    int i;
    for(i=0;i<size;i++){
        H[iparr[i]]++;
    }
    for(i = iparr[0];i<max;i++){
        if(H[i]>1){
            printf("duplicate element %d repeated for %d timies\n",i,H[i]);
        }
    }
}

int main(){
    int arr[11] = {6,7,8,8,9,10,11,11,11,12,13};
    duplicate(arr,11);
    duplicateVTwo(arr,11);
    duplicate_hashing(arr,11);
    return 0;
}
