//to get the sum --> you can use one element atmost once only and you have to get the subsequences in sorted order and unique in nature.
//elements in array can be duplicate so solution using loop is preferred.

#include<bits/stdc++.h>
using namespace std;

void solve(int index, int target, int arr[], vector<int> &temp, int n){
    //base case
    if(target==0){
        for(auto it:temp){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }

    //processing
    for(int i=index; i<n; i++){
        if(i>index && arr[i]==arr[i-1]){   //skip the element to ignore duplicacy of elements because array is sorted so consider one element once and then ignore remaining same numbers
            continue;                      //i>index helps to prevent if the conditions like if target==4 & array is [2, 2] so there is answer to store so don't ignore if first numbers are there
        }
        if(arr[i]>target){
            break;
        }

        temp.push_back(arr[i]);
        solve(i+1, target-arr[i], arr, temp, n);     //i+1 is passed as a index because we don't want every element to be added infinitely
        temp.pop_back();
    }
}

int main(){
    int arr[6]={2, 1, 1, 3, 4, 7};
    sort(arr, arr+6);
    vector<int> temp;
    int i=0;
    int n=6;
    int target=7;
    solve(i, target, arr, temp, n);

    return 0;
}