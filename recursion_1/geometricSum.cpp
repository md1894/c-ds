/*
Geometric Sum
Send Feedback
Given k, find the geometric sum i.e.

1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 

using recursion. Return the answer.
Sample Input :

3

Sample Output :

1.875

*/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


int p(int i, int j){
    if(j > 0){
        return i*p(i,j-1);
    }else{
        return 1;
    }
}

double geometricSum(int k) {
    // Write your code here
    if(k>=0){
        return (1.0/p(2,k))+geometricSum(k-1);
    }else{
        return 0;
    }
}





int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
