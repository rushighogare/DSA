#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], vector<int> &ans, int i, int n){
    //base case
    if(i>=n){
        if(ans.size()==0){
            cout<<"{}"<<endl;          //null set 
        }
        else{
            for(auto it: ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
        return ;
    }

    //inclusion and exclusion principle
    solve(arr, ans, i+1, n);         //this call is responsible for making subsequences
    ans.push_back(arr[i]);    

    solve(arr, ans, i+1, n);
    ans.pop_back();
}

int main(){
    int arr[3]={1, 2, 3};
    vector<int> ans;
    int i=0;
    int n=3;
    solve(arr, ans, i, n);
}