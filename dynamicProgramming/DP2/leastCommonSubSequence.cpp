/*

input --> two strings

output --> int value

input:
abcdef
zxvgtaiklpdqmnf

output:
3 --> a,d,f

*/

#include<iostream>
#include<string>
using namespace std;

int lcs_bruteForce(string s1, string s2){
    // base case
    if(s1.size() == 0 || s2.size() == 0){
        return 0;
    }

    if(s1[0] == s2[0]){
        return 1 + lcs_bruteForce(s1.substr(1), s2.substr(1));
    }else{
        int a = lcs_bruteForce(s1, s2.substr(1));
        int b = lcs_bruteForce(s1.substr(1), s2);
        int c = lcs_bruteForce(s1.substr(1), s2.substr(1));
        int ans = max(a, max(b, c));
        return ans;
    }
}

int lcs_memoization(string s1, string s2, int** ans){
    // base case
    if(s1.size() == 0 || s2.size() == 0){
        return 0;
    }

    int m = s1.size();
    int n = s2.size();

    if(ans[m][n] != -1){
        return ans[m][n];
    }

    int ans_, a, b, c;

    if(s1[0] == s2[0]){
            ans_ = 1 + lcs_memoization(s1.substr(1), s2.substr(1), ans);
    }else{
            a = lcs_memoization(s1, s2.substr(1), ans);
            b = lcs_memoization(s1.substr(1), s2, ans);
            c = lcs_memoization(s1.substr(1), s2.substr(1), ans);
            ans_ = max(a, max(b, c));
    }
    ans[m][n] = ans_;
    return ans_;
}

int lcs_memoization(string s1, string s2){
    int s = s1.size() + 1;
    int s_ = s2.size() + 1;
    int** ans = new int*[s];
    for(int i = 0; i < s; i++){
        ans[i] = new int[s_];
        for(int j = 0; j < s_; j++){
            ans[i][j] = -1;
        }
    }
    ans[0][0] = 0;
    return lcs_memoization(s1, s2, ans);
}

int lcs_DP(string s1, string s2){
   int m = s1.size();
	int n = s2.size();
	int **output = new int*[m+1];

	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}

	// Fill 1st row
	for(int j = 0; j <= n; j++) {
		output[0][j] = 0;
	}

	// Fill 1st col
	for(int i = 1; i <= m; i++) {
		output[i][0] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			// Check if 1st char matches
			if(s1[m-i] == s2[n-j]) {
				output[i][j] = 1 + output[i-1][j-1];
			}
			else {
				int a = output[i-1][j];
				int b = output[i][j-1];
				int c = output[i-1][j-1];
				output[i][j] = max(a, max(b, c));
			}
		}
	}

	return output[m][n];
}

int main(){
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<lcs_bruteForce(s1, s2)<<endl;
    cout<<lcs_memoization(s1, s2)<<endl;
    cout<<lcs_DP(s1, s2)<<endl;
    return 0;
}