#include<stdio.h>

int sum(int n){
    if(n>0){
        return n+sum(n-1);
    }else{
        return 0;
    }
}


int main(){
    printf("sum of first 10 natural numbers is %d\n",sum(10));
    return 0;
}
