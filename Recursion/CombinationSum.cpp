#include<bits/stdc++.h>
using namespace std;

void solve(int i, int target, int arr[], vector<int> &temp, int n){
    //base case
    if(i>=n){
        if(target==0){
            for(auto it: temp){
                cout<<it<<" ";
                
            }
            cout<<endl;
            
        }
        return ;
    }

    //inclusion and exclusion principle

    //inclusion (considering element infinite time to get equal to target)
    if(arr[i]<=target){
        temp.push_back(arr[i]);
        solve(i, target-arr[i], arr, temp, n);
        temp.pop_back();
    }

    //exclusion (not consider the current element, just go for next element)
    solve(i+1, target, arr, temp, n);
}

int main(){
    int arr[4]={2, 3, 4, 7};
    vector<int> temp;
    int i=0;
    int n=4;
    int target=7;
    solve(i, target, arr, temp, n);
}