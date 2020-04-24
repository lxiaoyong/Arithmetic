//
// Created by Liu on 2020/4/24.
//
#include <vector>

/*
 * 给你一个以行程长度编码压缩的整数列表 nums 。
 * 考虑每对相邻的两个元素 [freq, val] = [nums[2*i], nums[2*i+1]]（其中 i >= 0 ）
 * 每一对都表示解压后子列表中有 freq 个值为 val 的元素
 * 你需要从左到右连接所有子列表以生成解压后的列表。
 * 请你返回解压后的列表。
 * 且 nums.size()%2==0
 * */
using namespace std;
vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> result;
    int nums_length=nums.size();
    for(int i=1;i<nums_length;i=i+2){
        for(int j=0;j<nums[i-1];++j){
            result.push_back(nums[i]);
        }
    }
    return result;
}