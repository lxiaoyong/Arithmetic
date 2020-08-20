//
// Created  on 2020/8/20.
//
//题目：https://leetcode-cn.com/problems/minesweeper/
#include<vector>
using namespace std;
void board_DFS(vector<vector<char>>& board, const vector<int>&r_8, const vector<int>&c_8, int r, int c){
    int count=0;
    int row_board=(int)board.size();
    int column_board=(int)board[0].size();
    for(int i=0;i<8;++i){
        int new_r=r+r_8[i],new_c=c+c_8[i];
        if(new_r <0 || new_r >=row_board|| new_c <0 || new_c >=column_board)
            continue;
        if(board[new_r][new_c]=='M') ++count;
    }
    if(count==0){
        board[r][c]='B';
        for(int i=0;i<8;++i){
            int new_r=r+r_8[i],new_c=c+c_8[i];
            if(new_r <0 || new_r >=row_board|| new_c <0 || new_c >=column_board || board[new_r][new_c]!='E')
                continue;
            board_DFS(board, r_8, c_8, new_r, new_c);
        }
    }else{
        board[r][c]=count+'0';
    }
}
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int r=click[0],c=click[1];
    if(board[r][c]=='M') board[r][c]='X';
    else{
        vector<int>r_8{-1,-1,-1,0,0,1,1,1};
        vector<int>c_8{-1,0,1,-1,1,-1,0,1};
        board_DFS(board, r_8, c_8, r, c);
    }
    return board;
}