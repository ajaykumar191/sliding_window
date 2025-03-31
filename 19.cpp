// 930. Binary Subarrays With Sum

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

#include<bits/stdc++.h>
using namespace std;

int atmostKSumsubarrys(vector<int>arr,int k){
    int l=0;
    int r=0;
    int n=arr.size();
    int sum=0;
    int count=0;
    while(r<n){
        sum+=arr[r];
        while(sum>k && l<=r){
            sum-=arr[l];
            l++;
        }
        count+=(r-l+1);
        r++;
    }
    return count;
}

int main(){

    vector<int>arr={0,0,0,0,0};
    int goal=0;

    cout<<"The total number of subarrys with exactly sum goal are "<< atmostKSumsubarrys(arr,goal)-atmostKSumsubarrys(arr,goal-1)<<endl;

    return 0;
}
