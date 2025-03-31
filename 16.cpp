// Input: arr[] = {1, 2, 1, 0, 1, 1, 0}, k = 4
// Output: 5
// Explanation: {1, 2, 1} => sum = 4, length = 3 {1, 2, 1, 0}, {2, 1, 0, 1} => sum = 4, length = 4 {1, 0, 1, 1, 0} =>5 sum = 3, length = 5


// Input: 8, 2, 4, 0, 1, 1, 0, K = 9
// Output: 6

#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int>arr={8, 2, 4, 0, 1, 1, 0};
    int k=9;
    int maxLen=INT_MIN;
    int l=0;
    int r=0;
    int sum=0;
    while(r<arr.size()){
        sum+=arr[r];

        while(sum>k){
            sum-=arr[l];
            l++;
        }

        maxLen=max(maxLen,r-l+1);
        r++;
    }
    cout<<"The max lenght of the subarrys is "<<maxLen<<endl;

    return 0;
}