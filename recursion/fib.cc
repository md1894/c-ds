#include<stdio.h>

int fib(int n){
    if(n<=1){
        return n;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

// this version of fibonacci series program is not optimized 
// because if you trace the recursion , function with same value is called multiple times

int main(){
    printf("the 8th term in fibonacci series is %d\n",fib(8));
    return 0;
}
