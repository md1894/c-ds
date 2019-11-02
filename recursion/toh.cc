#include<stdio.h>

void towerOfHanoi(int numberOfDisks,int source,int auxillary,int destination){
    if(numberOfDisks > 0){
        towerOfHanoi(numberOfDisks-1,source,destination,auxillary);
        printf("(%d,%d)\n",source,destination);
        towerOfHanoi(numberOfDisks-1,auxillary,source,destination);
    }
}

int main(){
    towerOfHanoi(3,1,2,3);
    return 0;
}

// kindly read theory for tower of hanoi 
// then trace this code on paper to get understanding