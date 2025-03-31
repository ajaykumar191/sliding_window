// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="ADOBECODEBANC";
    string t="ABC";
    unordered_map<char,int>char_count;
    unordered_map<char,int>window_count;
    int l=0;
    int r=0;
    for(char c: t){
        char_count[c]++;
    }
    int formed=0;
    int min_len=INT_MAX;
    int startIndex=-1;
    int required=char_count.size();
    while(r<s.size()){
        char c=s[r];
        window_count[c]++;
        if(char_count.count(c) && window_count[c]==char_count[c]){
            formed++;
        }

        while(formed==required){

            if(r-l+1<min_len){
                min_len=r-l+1;
                startIndex=l;
            }
            window_count[s[l]]--;
            if(char_count.count(s[l]) && char_count[s[l]]> window_count[s[l]]){
                formed--;
            }
            l++;
        }
        r++;
    }
    if(startIndex==-1){
        cout<<"Nope not possible!"<<endl;
    }else{
        cout<<"The substring is "<<s.substr(startIndex,min_len);
    }
    
    

    return 0;
}