//
// Created on 2020/9/27.
// https://leetcode-cn.com/problems/bracket-lcci/
#include<vector>
#include <string>
using namespace std;
void gp_backtrack(vector<string> &result,string &s,int left,int right){
    if(left>right) return;
    if(left==0 && right==0) {
        result.push_back(s);return;
    }
    if(left>0){
        s.push_back('(');
        gp_backtrack(result,s,left-1,right);
        s.pop_back();
    }
    if(right>left){
        s.push_back(')');
        gp_backtrack(result,s,left,right-1);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string s;
    gp_backtrack(result,s,n,n);
    return result;
}