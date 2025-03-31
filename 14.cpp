//Smallest window in a string containing all characters of another string
// Input: S = “timetopractice”, P = “toc”
// Output: toprac
// Explanation: “toprac” is the smallest substring in which “toc” can be found.


// Input: S = “zoomlazapzo”, P = “oza”
// Output: apzo
// Explanation: “apzo” is the smallest substring in which “oza” can be found.
#include<bits/stdc++.h>
using namespace std;
int main(){

    string s="zoomlazapzo";
    string p="oza";
    unordered_map<char,int>char_count;
    for(char c:p){
        char_count[c]++;
    }
    int required = char_count.size();
    int left=0;
    int right=0;
    int formed=0;
    unordered_map<char,int>window_count;
    int min_len=INT_MAX;
    int startIndex=-1;

    while(right<s.size()){
        char c=s[right];
        window_count[c]++;
        if(char_count.count(c)  && window_count[c]==char_count[c]){
            formed++;
        }

        while(formed==required){

            if(right-left+1 <min_len){
                min_len=right-left+1;
                startIndex=left;
            }
            char left_char=s[left];
             window_count[left_char]--;
             if(char_count.count(left_char) && window_count[left_char]< char_count[left_char]){
                formed--;
             }
             left++;
        }
        right++;
    }
    if(startIndex==-1){
        cout<<"Nope not found!"<<endl;
    }
    else{
        cout<<"The string is "<<s.substr(startIndex,min_len);
    }




    return 0;
}