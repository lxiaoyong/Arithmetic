//
// Created  on 2020/10/7.
// https://leetcode-cn.com/problems/sort-colors/
#include<vector>
using namespace std;
void _swap(vector<int> &nums,int a,int b){
    int temp = nums[a];
    nums[a]=nums[b];
    nums[b]=temp;
}
void sortColors(vector<int>& nums) {
    int size = nums.size();
    int left=0;
    int right = size;
    int i=0;
    while(i<right){
        if(nums[i]==0){
            _swap(nums,i,left);
            ++left;// 把零往前换
            ++i;
        }else if(nums[i]==1){
            ++i;
        }else{
            --right;
            _swap(nums,i,right);
            // 把2往后换。由于不清楚换到 i 的数是否依旧为 2，故 i 的值不变。
        }
    }
}