// Input: s = “abc”, k = 2
// Output: 2
// Explanation: Possible substrings are {“ab”, “bc”}


// Input: s = “aba”, k = 2
// Output: 3
// Explanation: Possible substrings are {“ab”, “ba”, “aba”}


// Input: s = “aa”, k = 1
// Output: 3
// Explanation: Possible substrings are {“a”, “a”, “aa”}
#include<bits/stdc++.h>
using namespace std;
int atMostKDifferentSubArrays(string s,int k){
    int l=0;
    int r=0;
    int count=0;
    int n=s.size();
    unordered_map<char,int>mp;
    while(r<n){
        mp[s[r]]++;
        if(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        count+=(r-l+1);
        r++;
    }
    return count;
}

int main(){
    string s="abc";
    int k=2;
    int result=atMostKDifferentSubArrays(s,k)-atMostKDifferentSubArrays(s,k-1);
    cout<<"The total number subarrys with k different subarrys are "<<result<<endl;


    return 0;
}