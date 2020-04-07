//
// Created by Liu on 2020/4/6.
//
/*
 * 问题描述： https://leetcode-cn.com/problems/container-with-most-water/
 * */
#include <vector>
using namespace std;
/*
 * 由题目得，所能装的水的横截面积由两块板中较小块的长度shorter及两块板之间的距离(right-left)决定
 * 采用双指针left,right
 * left指向为第一块板，right指向最后一块板，可算出当前面积
 * 若向内移动较高块板，shorter不变，right-left的值变小，则面积肯定变小
 * 而向内移动较小块板，面积可能变大也可能变小，但变量max_area记录了最大的面积
 * 故向内移动较小块板，最终可以找出最大的面积
 * */
int maxArea(vector<int>& height) {
    int max_area=0;
    int area,shorter,left=0,right=height.size()-1;
    while(left<right){
        shorter=height[left]<height[right]?height[left]:height[right];
        area = shorter*(right-left);
        if(area>max_area) max_area=area;
        if(shorter==height[left]) ++left;
        else --right;
    }
    return max_area;
}