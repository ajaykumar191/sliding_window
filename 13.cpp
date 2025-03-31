// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="pwwkew";
    int n=s.size();
    unordered_map<char,int>mp;
    int r=0;
    int l=0;
    int maxLen=0;
    while(r<n){
        mp[s[r]]++;

        while(mp[s[r]]>1){
            mp[s[l]]--;
            l++;
        }
        maxLen=max(maxLen,r-l+1);
        r++;
    }

    cout<<"The total max lenght is "<<maxLen<<endl;

    return 0;
}