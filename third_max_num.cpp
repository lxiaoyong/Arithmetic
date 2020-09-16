//
// Created on 2020/9/16.
//https://leetcode-cn.com/problems/third-maximum-number/
#include <vector>
#include <set>
using namespace std;
int thirdMax(vector<int>& nums) {
    set<int> s;
    for(int i:nums){
        s.insert(i);
        if(s.size()>3 ) s.erase(s.begin());
    }
    return s.size()<3?*(--s.end()):*(s.begin());
}