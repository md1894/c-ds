#include<stdio.h>
#define OK 1
#define NOTOK 0

int isSorted(int* iparr,int size){
    if(size == 0 || size == 1){
        return OK;
    }else{
        if(iparr[size-2] > iparr[size-1]){
            return NOTOK;
        }else{
            return isSorted(iparr,size-1);
        }
    }
}

int isSortedi(int* iparr,int size){
    for(int i = 0 ; i < size-1 ; i++){
        if(iparr[i+1]<iparr[i]){
            return NOTOK;
        }
    }
    return OK;
}

int main(){
    int arr[6] = {23,46,135,200,700,600};
    if(isSorted(arr,6)){
        printf("\nyes sorted");
    }else{
        printf("\nnot sorted");
    }
    printf("\n");
    if(isSortedi(arr,6)){
        printf("\nyes sorted");
    }else{
        printf("\nnot sorted");
    }
    return 0;
}
