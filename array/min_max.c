#include<stdio.h>

void min_max(int* iparr,int size){;
    int min = iparr[0];
    int max = iparr[0];
    int i;
    for(i=0;i<size;i++){
        if(iparr[i]<min){
            min = iparr[i];
        }else if(iparr[i]>max){
            max = iparr[i];
        }
    }
    printf("\nthe min is %d and max is %d\n",min,max);
}


int main(){
    int arr[7]={11,6,9,2,7,4,1};
    int arr1[7] = {1,2,4,6,7,9,11};
    min_max(arr,7);
    return 0;
}
