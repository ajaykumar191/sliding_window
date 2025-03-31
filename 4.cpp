// Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
// Output: [3, 3, 4, 5, 5, 5, 6] 
// Explanation: 
// 1st contiguous subarray = [1 2 3] max = 3
// 2nd contiguous subarray = [2 3 1] max = 3
// 3rd contiguous subarray = [3 1 4] max = 4
// 4th contiguous subarray = [1 4 5] max = 5
// 5th contiguous subarray = [4 5 2] max = 5
// 6th contiguous subarray = [5 2 3] max = 5
// 7th contiguous subarray = [2 3 6] max = 6


// Input: arr[] = [5, 1, 3, 4, 2, 6], k = 1
// Output: [5, 1, 3, 4, 2, 6]
// Explanation: When k = 1, each element in the array is its own subarray, so the output is simply the same array.


// Input: arr[] = [1, 3, 2, 1, 7, 3], k = 3
// Output: [3, 3, 7, 7]
#include<bits/stdc++.h>
using namespace std;
int main(){

    vector<int>arr={1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k=3;
    deque<int>q;
    vector<int>ans;
    for(int i=0;i<k;i++){
        while(!q.empty() && arr[q.back()] <arr[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(arr[q.front()]);
    for(int i=k;i<arr.size();i++){
        if(q.front()==i-k){
            q.pop_front();
        }
        while(!q.empty() && arr[q.back()] <arr[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(arr[q.front()]);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}