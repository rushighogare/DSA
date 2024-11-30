#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], vector<int> &ans, int sum, int i){
        //base case
        if(i>=2){
            ans.push_back(sum);
            cout<<sum<<" ";
            return ;
        }
        
        sum+=arr[i];  
        solve(arr, ans, sum, i+1);   //pick the element 
        sum-=arr[i];
        solve(arr, ans, sum, i+1);      //not-pick the element
        
        
        //logic same as in combination sum, only target is not defined so store every possible sum
        //we can do like this also 
        // solve(arr, ans, sum+arr[i], i+1);        //inclusion
        // solve(arr, ans, sum, i+1);              //exclusion
        
    }

int main(){
    int sum=0;
    vector<int> ans;
    int arr[2]={2, 3};
    int i=0;
    solve(arr, ans, sum, i);
    
    return 0;
}