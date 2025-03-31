//Longest substring with at most k distinct characters
// Input: s = "aabacbebebe", k = 3
// Output: 7
// Explanation: "cbebebe" is the longest substring with 3 distinct characters.
// Input: s = "aaaa", k = 2
// Output: -1
// Explanation: There's no substring with 2 distinct characters.
// Input: s = "aabaaab", k = 2
// Output: 7
// Explanation: "aabaaab" is the longest substring with 2 distinct characters.

//Change the K to 2;
#include<bits/stdc++.h>
using namespace std;
int main(){

    string s="aabacbebebe";
    int k=2;
    int l=0;
    int r=0;
    int n=s.size();
    int maxLen=0;
    unordered_map<char,int>mp;

    while(r<n){
        mp[s[r]]++;
        while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0){
                mp.erase(s[l]);
            }
            l++;
        }
        maxLen=max(maxLen,r-l+1);
        r++;
    }

    cout<<"The maximum length of the subarry with k different characters is "<<maxLen<<endl;

    return 0;
}