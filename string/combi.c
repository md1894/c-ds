#include<stdio.h>
#define MAX 100

void comb(char* s,int k){
    int i;
    static int a[MAX]={0};
    static char res[MAX];
    if(s[k] == '\0'){
        res[k] = '\0';
        printf("%s\n",res);
    }
    else{
        for(i=0;s[i]!='\0';i++){
            if(a[i] == 0){
                a[i] = 1;
                res[k] = s[i];
                comb(s,k+1);
                a[i] = 0;
            }
        }
    }
}


int main(){
    char str[MAX];
    printf("Enter any string:\n");
    gets(str);
    comb(str,0);
    return 0;
}
