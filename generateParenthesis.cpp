//
// Created  on 2020/7/27.
//

// 题目：https://leetcode-cn.com/problems/generate-parentheses/submissions/

#include <vector>
#include <string>
using namespace std;

void add(vector<string> &v,string str,int l,int r){
    if(l==0){
        while(r!=0){
            str+=")";--r;
        }
        v.push_back(str);return;
    }
    if(r==0){
        v.push_back(str);return;
    }
    add(v,str+"(",l-1,r);
    if(l<r) add(v,str+")",l,r-1);
}

vector<string> generateParenthesis(int n) {
    vector<string> vs;
    add(vs,"",n,n);
    return vs;
}