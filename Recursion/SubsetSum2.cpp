//give unique subsets
#include<bits/stdc++.h>
using namespace std;

void solve(int index, int arr[], vector<int> &temp, int n){
    if(temp.size()!=0){
        for(auto it:temp){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    if(index==0){
        cout<<"{}"<<endl;
    }

    //processing
    for(int i=index; i<n; i++){
        if(i>index && arr[i]==arr[i-1]){   //skip the element to ignore duplicacy of elements because array is sorted so consider one element once and then ignore remaining same numbers
            continue;                      //don't ignore if first numbers are there
        }

        temp.push_back(arr[i]);
        solve(i+1, arr, temp, n);     //i+1 is passed as a index because we don't want every element to be added
        temp.pop_back();
    }
}

int main(){
    int arr[3]={1, 2, 2};
    sort(arr, arr+3);
    vector<int> temp;
    int i=0;
    int n=3;
    solve(i, arr, temp, n);

    return 0;
}