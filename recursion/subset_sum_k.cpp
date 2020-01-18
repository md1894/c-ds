
int subsetSumToK(int input[], int n, int output[][50], int k) {
    if(n == 0){
        if(k == 0){
            output[0][0] = 0;
            return 1;
        }else{
            return 0;
        }
    }
    int o1[500][50];
    int o2[500][50];
    int s1 = subsetSumToK(input+1, n-1, o1, k-input[0]);
    int s2 = subsetSumToK(input+1, n-1, o2, k);
    for(int i = 0; i < s1; i++){
        o1[i][0]++;
        
    }
}