/*
Code : No. of balanced BTs using DP
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Time complexity should be O(h).
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 10^7
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315
*/

#include <iostream>
#include <cmath>
using namespace std;

int binaryTreesOfHeightH(int h) {
    int mod = (int)(pow(10,9)) + 7;
    int h1, h2, h1_, h2_;
    int* ans = new int[h + 1];
    ans[0] = 1;
    ans[1] = 1;
    for(int i = 2; i <= h; i++){
        h1 = ans[i - 1];
        h2 = ans[i - 2];
        h1_ = (int)(((long)(h1)*h1) % mod);
        h2_ = (int)((2*(long)(h1)*h2) % mod);
        ans[i] = (h1_ + (h2_)) % mod;
    }
    return ans[h];
}

int main() {
    int h;
    cin >> h;
    int ans = binaryTreesOfHeightH(h);
    ans = ans % ((int)(pow(10, 9)) + 7);
    cout << ans << endl;
}