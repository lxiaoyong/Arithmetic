//
// Created on 2020/8/6.
//题目：https://leetcode-cn.com/problems/check-permutation-lcci/
#include <vector>
#include <string>
using namespace std;
bool CheckPermutation(string s1, string s2) {
    if(s1.size()!=s2.size()) return false;
    vector<int> vs1(26,0),vs2(26,0);
    for(char ch:s1) ++vs1[ch-'a'];
    for(char ch:s2) ++vs2[ch-'a'];
    return vs1==vs2;
}