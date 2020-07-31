//
// Created on 2020/7/31.
//
//题目：https://leetcode-cn.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
#include <vector>
#include <string>
using namespace std;
int minSteps(string s, string t) {
    vector<int> nums(26,0);
    for(char ch:s) ++nums[ch-'a'];
    int result=0;
    for(char ch:t){
        int index=ch-'a';
        if(nums[index]!=0) --nums[index];
        else ++result;
    }
    return result;
}