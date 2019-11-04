#include<stdio.h>
#define MAX 100

int fArr[MAX];

int fib(int n){
    if(n<=1){
        if(fArr[n] == -1){
            fArr[n] = n;
        }else{
            return fArr[n];
        }
        return fArr[n];
    }else{
        if(fArr[n] == -1){
            fArr[n] = fib(n-1) + fib(n-2);
        }else{
            return fArr[n];
        }
        return fArr[n];
    }
}


int notOptFib(int n){
    if(n<=1){
        return n;
    }else{
        return notOptFib(n-1) + notOptFib(n-2);
    }
}

// this version of fibonacci series program is not optimized 
// because if you trace the recursion , function with same value is called multiple times

int main(){
    for(int i = 0 ; i < MAX ; i++){
        fArr[i] = -1;
    }
    printf("the 8th term in fibonacci series is %d\n",fib(8));
     printf("the 8th term in fibonacci series is %d\n",notOptFib(8));
    return 0;
}
