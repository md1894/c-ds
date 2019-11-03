#include<stdio.h>

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    printf("\nthe gcd of 12 and 9 is %d\n",gcd(12,9));
    return 0;
}