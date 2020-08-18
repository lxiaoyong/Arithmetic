//
// Created on 2020/8/18.
// 题目：https://leetcode-cn.com/problems/number-of-1-bits/
#include <iostream>
int hammingWeight(uint32_t n) {
    int nums=0;
    while(n!=0){
        ++nums;
        n=n&(n-1);
    }
    return nums;
}

/*int hammingWeight(uint32_t n) {
    int nums=0;
    for(int i=0;i<32;++i){
        if((n>>i) & (0x00000001)) ++nums;
    }
    return nums;
}*/
