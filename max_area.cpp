//
// Created by Liu on 2020/4/6.
//
/*
 * 问题描述： https://leetcode-cn.com/problems/container-with-most-water/
 * */
#include <vector>
using namespace std;

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