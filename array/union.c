#include<stdio.h>

void printUnion(int* a1,int* a2,int s1,int s2){
    int i = 0,j = 0 ,k = 0;
    while(i<s1 && j<s2){
        if(a1[i]<a2[j]){
            printf("%d\t",a1[i++]);
        }else if(a2[j] < a1[i]) {
            printf("%d\t",a2[j++]);
        }else{
            printf("%d\t",a2[j++]);
            i++;
        }
    }
    
    while(i<s1){
        printf("%d\t",a1[i++]);
    }
    
    
    while(j<s2){
        printf("%d\t",a2[j++]);
    }
}


int main(){
    int a1[3]={5,6,7};
    int a2[5]={6,7,8,9,10};
    printUnion(a1,a2,3,5);
    return 0;
}
