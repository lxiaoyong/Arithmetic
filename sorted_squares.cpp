//
// Created on 2020/10/16.
// https://leetcode-cn.com/problems/squares-of-a-sorted-array/
#include<vector>
#include <cmath>
using namespace std;
vector<int> sortedSquares(vector<int>& A) {
    int left=0,right=(int)A.size()-1;
    vector<int> result(right+1,0);
    int index=right;
    while(left<=right){
        int abs_l = abs(A[left]);
        int abs_r = abs(A[right]);
        if(abs_l>abs_r){
            result[index] = abs_l*abs_l;
            ++left;
        }else{
            result[index] = abs_r*abs_r;
            --right;
        }
        --index;
    }
    return result;
}