// Input:  arr[] = {1, 12, -5, -6, 50, 3}, k = 4
// Output: Maximum average subarray of length 4 begins
//         at index 1.
// Maximum average is (12 - 5 - 6 + 50)/4 = 51/4

#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int>arr={1, 12, -5, -6, 50, 3};
    int k=4;
    int sum=0;
    int maxi=0;
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    maxi=max(maxi,sum);
    for(int i=k;i<arr.size();i++){
        sum-=arr[i-k];
        sum+=arr[i];
        maxi=max(maxi,sum);
    }
    cout<<"The avg sum is "<<maxi<<endl;

    return 0;
}