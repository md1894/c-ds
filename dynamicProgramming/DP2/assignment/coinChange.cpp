/*
Ways To Make Coin Change
Send Feedback
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, 
in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/

#include <iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
//     if(value == 0)
//         return 1;
    
//     if(value < 0 || numDenominations == 0)
//         return 0;
 
//     int a = countWaysToMakeChange(denominations, numDenominations, value - denominations[0]);
//     int b = countWaysToMakeChange(denominations + 1, numDenominations - 1, value);
//     return a + b;
    
    int** ans = new int*[value + 1];
    for(int i = 0; i <= value; i++){
        ans[i] = new int[numDenominations];
    }
    for(int i = 0; i < numDenominations; i++){
        ans[0][i] = 1;
    }
    for(int i = 1; i < value + 1; i++){
        for(int j = 0; j < numDenominations; j++){
            int x, y;
            if(denominations[j] > i){
                x = 0;
            }else{
                x = ans[i - denominations[j]][j];
            }
            
            if(j < 1){
                y = 0;
            }else{
                y = ans[i][j - 1];
            }
            
            ans[i][j] = x + y;
        }
    }
    return ans[value][numDenominations - 1];
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}