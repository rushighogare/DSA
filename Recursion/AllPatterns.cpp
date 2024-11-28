#include<bits/stdc++.h>
using namespace std;

bool print(int arr[], vector<int> &temp, int s, int sum, int i, int n){
    //base case
    if(i>=n){
        if(s==sum){
            for(auto it: temp){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;     //return true because we only want one subsequence and not all the subsequences which have given sum k
        }
        else{
            return false;
        }
    }

    temp.push_back(arr[i]);
    s+=arr[i];
    if(print(arr, temp, s, sum, i+1, n)==true){
        return true;
    }

    
    temp.pop_back();
    s-=arr[i];
    if(print(arr, temp, s, sum, i+1, n)==true){
        return true;
    }

    return false;
}

int main(){
    int sum=2;
    int arr[3]={1, 2, 1};
    int s=0;
    vector<int> temp;
    int n=3;
    int i=0;
    print(arr, temp, s, sum, i, n);
}

/*patterns
1. If you want to print all patterns --> by passing parameters and recursive calling
2. If you want to print 1 pattern --> return true/false and avoid recurion calls if you get those
3. count the subsquences --> //base case
                             return 1 / return 0
                             add all f() --> (function calls)
                             return count of all
*/