//
// Created by 刘晓涌 on 2020/8/12.
//
// 题目：https://leetcode-cn.com/problems/ugly-number-ii/
#include<vector>
using namespace std;
int nthUglyNumber(int n) {
    vector<int> uglyNums(n,0);
    uglyNums[0]=1;
    int iter2=0,iter3=0,iter5=0;
    int num2,num3,num5;
    for(int i=1;i<n;++i){
        num2=2*uglyNums[iter2];
        num3=3*uglyNums[iter3];
        num5=5*uglyNums[iter5];
        uglyNums[i]=min(min(num2,num3),num5);
        if(uglyNums[i]==num2) ++iter2;
        if(uglyNums[i]==num3) ++iter3;
        if(uglyNums[i]==num5) ++iter5;
    }
    return uglyNums[n-1];
}