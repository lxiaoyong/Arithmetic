//
// Created by Liu on 2020/4/17.
//
#include <vector>
using namespace std;
/*
 * nums是一个非负整数数组，初始位于首位置
 * 数组中的元素代表能跳跃的最远长度，判断是否能跳到最后一个元素处
 * */
bool canJump(vector<int>& nums) {
    int size=nums.size();
    if(size==0) return false;
    if(size==1) return true;
    bool flag=true;
    int j;
    // 非负数组，故如果无论如何都只能跳跃到元素为0的位置(非最后一个)上时，无法跳到最后一个元素处
    for(int i=size-2;i>=0;--i){
        if(nums[i]==0 && flag){
            flag=false;
            j=i;
        }
        if(!flag){
            //若元素为0的位置前，有能够直接跳到0的位置后面的，则说明此0能够被越过
            if(nums[i]>j-i) flag=true;
        }
    }
    return flag;
}
