#include <iostream>
#include <climits>
using namespace std;

int knapsack(int* weights, int* values, int n, int maxWeight){
    int** ans = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        ans[i] = new int[maxWeight + 1];
    }
    for(int itemsRemaining = 0; itemsRemaining <= n; itemsRemaining++){
        for(int maxWeights_ = 0; maxWeights_ <= maxWeight; maxWeights_++){
            if(itemsRemaining == 0 || maxWeights_ == 0){
                ans[itemsRemaining][maxWeights_] = 0;
            }else if(weights[itemsRemaining - 1] > maxWeights_){
                ans[itemsRemaining][maxWeights_] = ans[itemsRemaining - 1][maxWeights_];
            }else{
                int a = values[itemsRemaining - 1] + 
                    ans[itemsRemaining - 1][maxWeights_ - weights[itemsRemaining - 1]];
                int b = ans[itemsRemaining - 1][maxWeights_];
                ans[itemsRemaining][maxWeights_] = max(a, b);
            }
        }
    }
    return ans[n][maxWeight];
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