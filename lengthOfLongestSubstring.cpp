//
// Created  on 2020/7/28.
//

//题目：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include<string>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_set<char> uSetCh;
    int maxLen=0,currentLen=0;
    int same=0;
    for(char ch:s){
        if(uSetCh.find(ch)!=uSetCh.end()){
            for(int i=same;i<s.size();++i){
                if(s[i]!=ch) uSetCh.erase(s[i]);
                else{
                    same=i+1;break;
                }
            }
            currentLen=uSetCh.size();
        } else{
            uSetCh.insert(ch);
            ++currentLen;
        }
        maxLen=max(maxLen,currentLen);
    }
    return maxLen;
}
