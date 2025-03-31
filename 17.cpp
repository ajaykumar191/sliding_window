// Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
// Output: 6
// Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.


// Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
// Output: 5
// Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.


// Input: arr[] = [10, -10, 20, 30], k = 5
// Output: 0
// Explanation: No subarray with sum = 5 is present in arr[].

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr={10, 5, 2, 7, 1, -10};
    int k=15;

    int maxLen=0;
    int sum=0;
    unordered_map<int,int>prefixSumMap;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];

        if(sum==k){
            maxLen=i+1;
        }

        if(prefixSumMap.find(sum-k)!=prefixSumMap.end()){

            maxLen=max(maxLen,i-prefixSumMap[sum-k]);
        }
        if(prefixSumMap.find(sum)==prefixSumMap.end()){
            prefixSumMap[sum]=i;
        }
    }
    cout<<"The max lenght of the subarry with exactly sum k is "<<maxLen<<endl;

    return 0;
}