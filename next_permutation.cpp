//
// Created  on 2020/11/12.
// https://leetcode-cn.com/problems/next-permutation/
#include<vector>
using namespace std;

void swap(vector<int>& nums,int index_1,int index_2){
    int val = nums[index_1];
    nums[index_1] = nums[index_2];
    nums[index_2] = val;
}
void min_permutation(vector<int>& nums,int start,int end){
    int left = start,right = end;
    while(left<right){
        swap(nums,left,right);
        ++left;--right;
    }
}
void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    if(size<2) return;
    int last_index = size-1,i=size-2;
    for( ;i>=0;--i)
        if(nums[i]<nums[i+1]) break;
    int start=0;
    if(i!=-1){
        int t = last_index,val = nums[i];
        while(t>i && nums[t]<=val) --t;
        swap(nums,i,t);
        start=i+1;
    }
    min_permutation(nums,start,last_index);
}