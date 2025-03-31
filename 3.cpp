// Given a word pattern and a string text consisting of lowercase characters, the task is to return the count of substrings in text which are anagrams of the pattern.

// Examples: 

// Input : text = “forxxorfxdofr”, pattern = “for”
// Output : 3
// Explanation : Anagrams present are for, orf and ofr. Each appears in the text once and hence the count is 3.


// Input : text = “aabaabaa”, pattern = “aaba”
// Output : 4
// Explanation : Anagrams present are aaba and abaa. Each appears twice in the text and hence the count is 4.
#include<bits/stdc++.h>
using namespace std;
int main(){

    string text="aabaabaa";
    string pattren="aaba";
    if(pattren.size()>text.size()){

        cout<<"Not possible "<<endl;
        return 0;
    }
    vector<int>pattrenArray(26,0);
    for(int i=0;i<pattren.size();i++){
        pattrenArray[pattren[i]-'a']++;
    }
    // for(int i=0;i<26;i++){
    //     cout<<pattrenArray[i]<<" ";
    // }
    int k=pattren.size();
    vector<int>textArray(26,0);
    for(int i=0;i<k;i++){
        textArray[text[i]-'a']++;
    }
    int count=0;
    if(textArray==pattrenArray){
        count++;
    }
    for(int i=k;i<text.size();i++){
        textArray[text[i-k]-'a']--;
        textArray[text[i]-'a']++;
        if(textArray==pattrenArray){
            count++;
        }
    }
    cout<<"The total count is "<<count<<endl;


    return 0;
}