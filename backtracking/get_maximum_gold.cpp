//
// Created on 2020/9/26.
// https://leetcode-cn.com/problems/path-with-maximum-gold/
#include <vector>
using namespace std;

class Solution {
private:
    int maximum_gold=0;
public:
    void gmg_backtrack(vector<vector<int>> &grid,int row,int col,int gold){
        int down_board=grid.size(),right_board=grid[0].size();
        int temp=0;
        if(grid[row][col]!=0){
            gold+=grid[row][col];
            temp=grid[row][col];
            grid[row][col]=0;
            // right
            if(col+1<right_board && grid[row][col+1]!=0) gmg_backtrack(grid,row,col+1,gold);
            // down
            if(row+1<down_board && grid[row+1][col]!=0) gmg_backtrack(grid,row+1,col,gold);
            // left
            if(col-1>=0 && grid[row][col-1]!=0) gmg_backtrack(grid,row,col-1,gold);
            // up
            if(row-1>=0 && grid[row-1][col]!=0) gmg_backtrack(grid,row-1,col,gold);
        }
        grid[row][col]=temp;
        maximum_gold=max(maximum_gold,gold);
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int gold=0;
        int row = grid.size(),col = grid[0].size();
        for(int i=0;i<row;++i)
            for(int j=0;j<col;++j){
                if(grid[i][j]!=0 ) gmg_backtrack(grid,i,j,gold);
            }
        return maximum_gold;
    }
};