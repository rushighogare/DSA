#include<bits/stdc++.h>
using namespace std;

void solve(int i, int target, int arr[], vector<int> &temp, int n){
    //base case
    if(i>=n){
        if(target==0){          //we are making target to zero by adding the array elements, if it gets zero means we got subsequence and print that subsequence
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
        solve(i, target-arr[i], arr, temp, n);   // i is not changed i.e infinite picking an element
        temp.pop_back();
    }

    //exclusion (not consider the current element, just go for next element)
    solve(i+1, target, arr, temp, n);             // i is changed i.e exclude current element and move to the next element
}

void solve2(int index, int target, int arr[], vector<int> &temp, int n){
    //base case
    if(target==0){
        for(auto it: temp){
            cout<<it<<" ";        
        }
        cout<<endl;   
        return ;       
    }
    if(target<0){
        return ;
    }

    //processing
    for(int i=index; i<n; i++){
        temp.push_back(arr[i]);
        solve2(i, target-arr[i], arr, temp, n);   //we are not changing index because we can use single element infinite times
        temp.pop_back();
    }
}

int main(){
    int arr[4]={2, 3, 4, 7};
    vector<int> temp;
    int i=0;
    int n=4;
    int target=7;
    solve2(i, target, arr, temp, n);
}
//T.C. (2^n)*k
//S.C. k*x