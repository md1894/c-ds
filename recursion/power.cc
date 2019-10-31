#include<stdio.h>

int power(int base,int raiseto){
    if( raiseto > 0){
        return base*power(base,raiseto-1);
    }else{
        return 1;
    }
}

int main(){
    printf("2 raise to 4 is %d\n",power(78,4));
    return 0;
}