//
// Created on 2020/8/31.
// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
#include<set>
#include<vector>
#include <string>
using namespace std;
void help_permutation(const string& s,string str,vector<string> & result,vector<bool>& used){
    if(str.size()==s.size()){
        result.push_back(str);
        return;
    }
    set<char> set_char;
    for(int i=0;i<s.size();++i){
        if(set_char.find(s[i])!=set_char.end()) continue;
        if(!used[i]){
            str+=s[i];
            used[i]=true;
            set_char.insert(s[i]);
            help_permutation(s,str,result,used);
            used[i]=false;
            str.pop_back();

        }
    }
}
vector<string> permutation(string s) {
    int len=s.size();
    vector<bool> used(len,false);
    vector<string> result;
    help_permutation(s,"",result,used);
    return result;
}