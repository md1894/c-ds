
#include<iostream>
using namespace std;

void print_subset_k(int a[],int s, int k, int op[], int m){
    if(s == 0){
        if(k == 0){
            for(int i = 0; i < m; i++){
                cout<<op[i]<<" ";
            }
            cout<<endl;
        }else{
            return;
        }
    }
    
    print_subset_k(a+1, s-1, k, op, m);
    op[m] = a[0];
    m++;
    print_subset_k(a+1, s-1, k-a[0], op, m);
    }
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int a[200];
    print_subset_k(input, size, k, a, 0);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
