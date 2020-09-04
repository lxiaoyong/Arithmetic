//
// Created  on 2020/9/4.
//https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include <vector>
using namespace std;
int binary_search(vector<int>& nums,int target){
    int left=0,right=(int)nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]<=target) left=mid+1;
        else right=mid-1;
    }
    return right;
}
int search(vector<int>& nums, int target) {
    return binary_search(nums,target)-binary_search(nums,target-1);
}

