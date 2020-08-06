//
// Created  on 2020/8/6.
//题目：https://leetcode-cn.com/problems/is-unique-lcci/
#include<string>
bool isUnique(std::string astr) {
    int nums=0,index=0;
    for(char ch:astr){
        index=ch-'a';
        if((nums & (1<<index) )!=0) return false;
        nums|=(1<<index);
    }
    return true;
}
/*bool isUnique(string astr) {
        for(int i=0;i<astr.size();++i){
            for(int j=i+1;j<astr.size();++j){
                if(astr[i]==astr[j]) return false;
            }
        }
        return true;
    }*/