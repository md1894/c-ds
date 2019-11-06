#include<stdio.h>

int rbsearch(int* iparr,int left,int right,int key){
    if(right>=left){
        int mid = (left+right)/2;
        if(key == iparr[mid]){
            return mid;
        }else if(key<iparr[mid]){
            return rbsearch(iparr,left,mid-1,key);
        }else{
            return rbsearch(iparr,mid+1,right,key);
        }
    }
    return -1;
}

int ibsearch(int* iparr,int left,int right,int key){
    while(left <= right){
        int mid = (left+right)/2;
        if(key == iparr[mid]){
            return mid;
        }else if(key<iparr[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return -1;

}


int main(){
    int arr[6] = {23,46,135,200,252,785};
    printf("\n element returned by bsearch is %d",arr[rbsearch(arr,0,5,200)]);
    printf("\n element returned by bsearch is %d",arr[ibsearch(arr,0,5,200)]);
    return 0;
}
