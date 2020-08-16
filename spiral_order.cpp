//
// Created  on 2020/8/16.
//
//题目： https://leetcode-cn.com/problems/spiral-matrix/
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> nums;
    int column_num=matrix.size();
    if(column_num==0) return nums;
    int row_num=matrix[0].size();
    if(row_num==0) return nums;
    int all=column_num*row_num;
    int left_border=0,right_border=row_num-1,up_border=0,down_border=column_num-1;
    int cur=0;
    for(int i=0;i<all;){
        // left to right
        while(cur<=right_border){
            nums.push_back(matrix[up_border][cur]);++i;
            ++cur;
        }
        if(++up_border>down_border) break;
        cur=up_border;
        // up to down
        while(cur<=down_border){
            nums.push_back(matrix[cur][right_border]);++i;
            ++cur;
        }
        if(--right_border<left_border) break;
        cur=right_border;
        // right to left
        while(cur>=left_border){
            nums.push_back(matrix[down_border][cur]);++i;
            --cur;
        }
        if(--down_border<up_border) break;
        cur=down_border;
        // down to up
        while(cur>=up_border){
            nums.push_back(matrix[cur][left_border]);++i;
            --cur;
        }
        if(++left_border>right_border) break;
        cur=left_border;
    }
    return nums;
}