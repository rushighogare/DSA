//giving output by changing array in all type of permutations by changing there places in itself
#include<bits/stdc++.h>
using namespace std;


//S.C. --> O(n)+O(n)  T.C. --> T.C. n!*n
void solve(int n, int arr[], vector<int> &demo, vector<int> &temp, vector<vector<int>> &ans){
    //base case
    if(temp.size()==n){
        ans.push_back(temp);
    }

    for(int i=0; i<n; i++){            //here we have to include all elements in every case so start loop from 0 every time 
        if(demo[i]==0){
            temp.push_back(arr[i]);
            demo[i]=1;
            solve(n, arr, demo, temp, ans);
            demo[i]=0;
            temp.pop_back();
        }
    }
}

//optimal S.C -->   T.C. --> n!*n
void solve2(vector<int> &nums, vector<vector<int>> &ans, int j){
    //base case
    if(j>=nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int i=j; i<nums.size(); i++){         //i=j because we don't want to take duplicates by swapping with its own index although it is done once
        swap(nums[i], nums[j]);
        solve2(nums, ans, j+1);
        swap(nums[i], nums[j]);
    }
}

int main(){
    int arr[3]={1, 2, 3};
    vector<int> nums={1, 2, 3};
    int n=3;
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> demo(3, 0);           //this array is used to hashing to not select element twice if it is selected once
    // solve(n, arr, demo, temp, ans);

    int j=0;
    solve2(nums, ans, j);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}