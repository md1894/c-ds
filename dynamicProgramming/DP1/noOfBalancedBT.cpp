/*
Code : No. of balanced BTs
Send Feedback
Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
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
using namespace std;
#include <cmath>

int balancedBTs(int h) {
    if(h <= 1) {
        return 1;
    }

    int mod = (int) (pow(10, 9)) + 7;
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    /*very very important*/
    /*
    if x*x where x is int , then system will save the calculation inside a
    temporary buffer of type int , because of both the operands are int
    so we have to explicitly type cast one operand to long
    so that temporary buffer will be of type int
    and our calculation will not go out of bond
    */
    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2* (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;


    //int ans = (x*x + 2*x*y) % mod;
    return ans;
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
