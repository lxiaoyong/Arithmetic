//
// Created on 2020/7/26.
//

// 题目：https://leetcode-cn.com/problems/add-strings/
#include <string>
using namespace std;
string addStr(const string &,const string &);

string addStrings(const string &num1, const string &num2) {
    if(num1.size()>num2.size()) return addStr(num1,num2);
    else return addStr(num2,num1);
}
string addStr(const string &longerStr,const string &shorterStr){
    int lLen=longerStr.size();
    int sLen=shorterStr.size();
    int c=0,result=0;
    string sum(sLen,'0');
    for(int i=sLen-1,j=lLen-1;i>-1;--i,--j){
        result=longerStr[j]+shorterStr[i]+c-96;
        sum[i]=result%10+48;
        c=result>9?1:0;
    }
    string subLongerStr=longerStr.substr(0,lLen-sLen);
    if(c==1){
        for(int i=lLen-sLen-1;i>-1;--i){
            result=c+subLongerStr[i]-48;
            subLongerStr[i]=result%10+48;
            c=result>9?1:0;
        }
        if(c==1) return '1'+subLongerStr+sum;
    }
    return subLongerStr+sum;
}
