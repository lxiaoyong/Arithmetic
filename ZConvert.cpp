//
// Created by 刘晓涌 on 2020/7/29.
//
// 题目：https://leetcode-cn.com/problems/zigzag-conversion/
#include<vector>
#include<string>
using namespace std;
string convert(string s, int numRows) {
    if(numRows==1) return s;
    vector<string> vs(numRows);
    int current_row=0;
    bool direction=false;
    for(const char& ch:s){
        vs[current_row]+=ch;
        if(current_row==0 || current_row==numRows-1)
            direction=!direction;
        current_row+=(direction?1:-1);
    }
    string result;
    for(const string& str:vs) result+=str;
    return result;
}
/*string convert(string s, int numRows) {
    if(numRows==1) return s;
    vector<string> vs(numRows);
    int n=2*numRows-2;
    for(int i=0;i<numRows;++i){
        for(int j=i; j < s.size(); j+=2){
            if(j % n == i || j % n == n-i) vs[i]+=s[j];
        }
    }
    string result;
    for( const string &str:vs) result+=str;
    return result;
}*/
