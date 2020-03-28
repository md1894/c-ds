#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 


// int allWys(int x, int n, int* ans){
//     if()
// }

// int allWays(int x, int n) {
//     int* ans = new int[n + 1];
//     memset(ans, 0, n + 1);
//     return allWays(x, n, ans);
// }


int allWays(int x, int n) {
    if(x == 0)
        return 1;
    
    if(x < 0)
        return 0;
    
    int a = 1;
    int b = 0;
    bool isAns = false;
    int count = 0;
    while(x - b > 0){
        b = (int)pow(a, n);
        if(allWays(x - b, n) >= 1){
            count++;
        }
    }
    return count;
}


int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}