#include<stdio.h>

int rlsearch(int* iparr,int left,int right,int key){
    if(right < left){
        return -1;
    }
    if(key == iparr[left]){
        return left;
    }
    if(key == iparr[right]){
        return right;
    }
    return rlsearch(iparr,left+1,right-1,key);
}

void swap(int* a,int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int ilsearch(int* iparr,int size,int key){
    for(int i = 0 ; i < size ; i++){
        if(key == iparr[i]){
            return i;
        }
    }
    return -1;
}


int main(){
    int arr[6] = {23,46,135,200,252,785};
    printf("\n element returned by bsearch is %d",arr[rlsearch(arr,0,5,200)]);
    printf("\n element returned by bsearch is %d",arr[ilsearch(arr,6,200)]);
    return 0;
}
