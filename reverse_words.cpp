//
// Created  on 2020/9/9.
// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
#include <string>
using namespace std;
string reverse_string(string &s,int first,int last){
    for(int i=first;i<(last+first)/2;++i){
        swap(s[i],s[last-1-i+first]);
    }
    string str(s.begin()+first,s.begin()+last);
    return str;
}
string reverseWords(string s) {
    int len=s.size();
    if(len==0) return "";
    int first=-1,last=-1;
    for(int i=0;i<len;++i)
        if(s[i]!=' '){
            first=i;break;
        }
    for(int i=len-1;i>=0;--i)
        if(s[i]!=' '){
            last=i;break;
        }
    if(first==-1 && last==-1 ) return "";
    s=reverse_string(s,first,last+1);
    len=s.size();
    string result;
    for(int i=0;i<len;++i){
        if(s[i]==' ') continue;
        else{
            first=i;
            while(i!=len && s[i]!=' ') ++i;
            last=i;
            string t=reverse_string(s,first,last);
            if(i!=len) t+=" ";
            result+=t;
        }
    }
    return result;
}