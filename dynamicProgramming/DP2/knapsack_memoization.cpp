#include <iostream>
#include <climits>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight, int** ans){
    
    if(maxWeight == 0 || n == 0){
        return 0;
    }
    
    // check weather ans is present
    if(ans[n][maxWeight] != INT_MIN){
        return ans[n][maxWeight];
    }
    
    if(weights[0] > maxWeight){
        ans[n][maxWeight] = knapsack(weights + 1, values + 1, n - 1, maxWeight, ans);
        return ans[n][maxWeight];
    }else{
        int a = values[0] + knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0],
                                     ans);
        int b = knapsack(weights + 1, values + 1, n - 1, maxWeight, ans);
        
        ans[n][maxWeight] = max(a, b);
        return ans[n][maxWeight];
    }
}

int knapsack(int* weights, int* values, int n, int maxWeight){
    int** ans = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        ans[i] = new int[maxWeight + 1];
        for(int j = 0; j < maxWeight + 1; j++){
            ans[i][j] = INT_MIN;
        }
    }
    for(int i = 0; i < n + 1; i++){
        ans[i][0] = 0;
    }
    for(int i = 1; i < maxWeight + 1; i++){
        ans[0][i] = 0;
    }
    return knapsack(weights, values, n, maxWeight, ans);
}


int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}