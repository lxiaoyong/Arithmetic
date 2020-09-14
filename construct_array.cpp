//
// Created  on 2020/9/14.
// https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
#include<vector>
using namespace std;

vector<int> constructArr(vector<int>& a) {
    int len=a.size();
    if(len==0) return {};
    vector<int> b(len,1);
    for(int i=len-1;i>0;--i)
        b[i-1]=b[i]*a[i];
    int t=1;
    for(int i=1;i<len;++i){
        t*=a[i-1];
        b[i]*=t;
    }
    return b;
}