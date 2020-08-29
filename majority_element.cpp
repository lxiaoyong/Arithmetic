//
// Created on 2020/8/29.
// https://leetcode-cn.com/problems/majority-element/
#include <vector>
int majorityElement(std::vector<int>& nums) {
    int result=nums[0],num=1;
    for(int i=1;i<nums.size();++i){
        if(num==0){
            result=nums[i];++num;continue;
        }
        num+=(result==nums[i]?1:-1);
    }
    return result;
}