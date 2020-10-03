//
// Created  on 2020/10/3.
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0,right =(int)nums.size()-1;
    vector<int> result(2,-1);
    while(left<right){
        int mid = left+(right-left)/2;
        if(nums[mid]>=target) right=mid;
        else left=mid+1;
    }
    if(right<nums.size() && nums[right]==target) result[0]=right;
    else return result;
    left=right,right=(int)nums.size()-1;
    while(left<right){
        int mid = (left+right)/2+1;
        if(nums[mid]<=target) left=mid;
        else right=mid-1;
    }
    result[1]=left;
    return result;
}