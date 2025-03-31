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
    int totalNumberOfSubArrys=(n*(n+1))/2;
    //totalNumberOfSubArrys=atleastKDiffrentArrys+atMostKDifferent(k-1)Arrys;
    k=k-1;
    while(r<n){
       mp[arr[r]]++;

       if(mp.size()>k){
            mp[arr[l]]--;
            if(mp[arr[l]]==0){
                mp.erase(arr[l]);
            }
            l++;  
       }
       count+=(r-l+1);
       r++;
    }
    cout<<"The total number of subarrys with atmost k different elements are "<<count<<endl;
}