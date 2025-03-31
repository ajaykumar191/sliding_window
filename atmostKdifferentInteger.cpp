#include<bits/stdc++.h>

using namespace std;
int main(){

    //nums = [1,2,1,2,3], k = 2;
    vector<int>arr={1,2,1,2,3};
    int k=2;
    int n=arr.size();

    int l=0;
    int r=0;
    unordered_map<int,int>mp;
    int count=0;
    while(r<n){
        mp[arr[r]]++;
        while(mp.size()>k){
            mp[arr[l]]--;
            if(mp[arr[l]]==0){
                mp.erase(arr[l]);
            }
            l++;
        }
        count+=(r-l+1);
        r++;

    }
    cout<<"The total number of subarrys are "<<count<<endl;

    return 0;
}