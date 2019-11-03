#include<stdio.h>


int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
    
}

void rotation(int* arr,int size,int element){
    for(int i = 0 ; i < gcd(size,element) ; i++){
        int temp = arr[i];
        int j = i;
        while(1){
            int k = j + element;
            if(k>=size)
                k = k - size;

            if(k==i)
                break;

            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
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