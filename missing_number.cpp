//
// Created on 2020/9/7.
// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
#include <vector>
using namespace std;
int missingNumber(vector<int>& nums) {
    int left=0,right=(int )nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==mid) left=mid+1;
        else right=mid-1;
    }
    return left;
}