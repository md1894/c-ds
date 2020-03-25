
#include<iostream>
#include<string>
using namespace std;

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    int m = s1.size();
    int n = s2.size();
    
    int** ans = new int*[m+1];
    for(int i = 0; i < m + 1; i++){
        ans[i] = new int[n + 1];
    }
    
    //fill first row
    for(int i = 0; i < n + 1; i++){
        ans[0][i] = i;
    }
    
    //fill first column
    for(int i = 1; i < m + 1; i++){
        ans[i][0] = i;
    }
    
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
            // where first character matches
            if(s1[m - i] == s2[n - j]){
                ans[i][j] = ans[i - 1][j - 1];
            }else{
                // insert
                int a = ans[i - 1][j];
                //delete
                int b = ans[i][j - 1];
                //update
                int c = ans[i - 1][j - 1];
                
                ans[i][j] = min(a,min(b,c)) + 1;
            }
        }
    }
    return ans[m][n];
}



int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}