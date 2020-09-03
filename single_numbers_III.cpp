//
// Created  on 2020/9/3.
//  https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
#include <vector>
using namespace std;

vector<int> singleNumbers(vector<int>& nums) {
    int c=0;
    for(int i:nums)
        c^=i;
    c&=(-c);
    int first=0,second=0;
    for(int i:nums)
        if(c&i) first^=i;
        else second^=i;
    return vector<int>{first,second};
}