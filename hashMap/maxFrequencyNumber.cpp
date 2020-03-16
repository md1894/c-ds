#include<iostream>
#include<unordered_map>
#include <utility>
#include <iterator>
using namespace std;


int highestFrequency(int *input, int n){
    unordered_map<int,int> mp;
    pair<int, int> max_pair;
    for(int i = 0; i < n; i++){
        if(mp.count(input[i]) == 0){
            //mp.insert(make_pair(input[i], 0));
            mp[input[i]] = 0;
        }else{
            mp[input[i]]++;
        }
    }
    max_pair.first = input[0];
    max_pair.second = mp[input[0]];
    unordered_map<int,int>::iterator ptr;
    for(ptr = mp.begin(); ptr != mp.end(); ptr++){
        if(max_pair.second < ptr->second){
            max_pair.second = ptr->second;
            max_pair.first = ptr->first;
        }
    }
    return max_pair.first;
}

int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<maxKey;
    return 0;
}
