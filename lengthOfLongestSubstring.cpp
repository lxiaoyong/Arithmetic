//
// Created  on 2020/7/28.
//

//题目：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include<string>
#include <unordered_map>
using namespace std;
int length_of_longest_substring(string s) {
    int max_length=1,cur_length=0;
    unordered_map<char,int> unmap_char_int;
    for(int i=0;i<s.size();++i){
        if(unmap_char_int.find(s[i]) == unmap_char_int.end()){
            ++cur_length;
            unmap_char_int.insert(make_pair(s[i], i));
            continue;
        }else{
            max_length=max(max_length,cur_length);
            int index=unmap_char_int[s[i]];
            cur_length=(index<i-cur_length ? cur_length+1 :min(cur_length,i-index));
            unmap_char_int[s[i]]=i;
        }
    }
    max_length=max(max_length,cur_length);
    return max_length;
}
// 第一版

#include<unordered_set>

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
