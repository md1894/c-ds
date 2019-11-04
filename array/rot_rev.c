#include<stdio.h>

void rev(int* arr , int start , int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rot(int* arr , int size , int element){
    if(element == 0)
        return;
    
    rev(arr,0,element-1);
    rev(arr,element,size-1);
    rev(arr,0,size-1);
}


int main(){
    int arr[6] = {1,2,3,4,5,6};
    rot(arr,6,2);
    for(int i = 0 ; i < 6 ; i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}