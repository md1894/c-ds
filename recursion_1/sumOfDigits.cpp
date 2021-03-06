/*
Sum of digits (recursive)
Send Feedback
Write a recursive function that returns the sum of the digits of a given integer.
Sample Input :

12345

Sample Output :

15


*/



#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if(n>0){
        return (n%10) + sumOfDigits(n/10);
    }
}



int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
