#include<stdio.h>


void rotation(int *arr,int size,int elements){
    int temp[elements];
    int i;
    for(i = 0 ; i < size ; i++){
        printf("%d\n",arr[i]);
    }
    for(i = 0 ; i < elements ; i++){
        temp[i] = arr[i];
    }

    for(i = elements ; i < size ; i++){
         arr[i - elements] = arr[i];
    }


    for(i = size - elements ; i < size ; i++){
        arr[i] = temp[i-(size-elements)];
    }
}

int main(){
    int arr[6] = {1,2,3,4,5,6};
    rotation(arr,6,2);
    for(int i = 0 ; i < 6 ; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}