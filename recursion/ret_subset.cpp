#include <iostream>
using namespace std;

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Dont print the subsets, just save them in output.
***/

void createCopy(int s, int op[][20]){
    for(int i = s; i < 2*s; i++){
        op[i][0] = op[i-s][0];
        for(int j = 1; j <= op[i][0]; j++){
            op[i][j] = op[i-s][j];
        }
    }
}

void shiftAndAdd(int op[], int size, int el){
    int i;
    for(i = size; i > 0; i--){
        op[i] = op[i-1];
    }
    op[i] = el;
}

int subset(int input[], int n, int output[][20]) {
    // Write your code here
    if(n == 0){
        output[0][0] = 0;
        return 1;
    }
    
    int smallOutput = subset(input + 1, n - 1, output);
    createCopy(smallOutput, output);
    for(int i = smallOutput; i < smallOutput*2; i++){
        output[i][0] = output[i - smallOutput][0] + 1;
        int size = output[i][0] + 1;
        shiftAndAdd(output[i] + 1, size, input[0]);
    }
    
    return 2*smallOutput;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
