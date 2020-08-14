//
// Created on 2020/8/13.
//
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int firstBit=0,secondBit=0;
    for(int x:nums){
        /*
         * if (secondeBit==0)
         *    if (x==0)  firstBit=firstBit;
         *    else firstBit=~firstBit;
         * else
         *    firstBit=0;
         * */
        firstBit=~secondBit & (x ^ firstBit);
        /*
         * if (firstBit==0)
         *     if(x=0) secondBit=secondBit;
         *     else secondBit=~secondBit;
         * else
         *     secondBit=0;
         * */
        secondBit= ~firstBit & (x^secondBit);
    }
    return firstBit;
}