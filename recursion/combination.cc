#include<stdio.h>

int c(int n,int r){
        if(n==r || r==0){
            return 1;
        }else{
            return c(n-1,r)+c(n-1,r-1);
        }
}

// find the combination by using pascal triangle

int main(){
    printf(" n = 6 , r = 3 == %d",c(12,5));
    return 0;
}
