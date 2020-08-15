//
// Created  on 2020/8/15.

//题目：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
#include <vector>
using namespace std;
bool _verifyPostorder(vector<int>& postorder,int start,int finish){
    if(start>=finish) return true;
    int root_val = postorder[finish];
    int i=0,j=0;
    for(;i<finish;++i){
        if(postorder[i]>root_val)
            break;
    }
    for(j=i+1;j<finish;++j){
        if(postorder[j]<root_val)
            return false;
    }
    return _verifyPostorder(postorder,start,i-1) && _verifyPostorder(postorder,i,finish-1);
}
bool verifyPostorder(vector<int>& postorder) {
    return _verifyPostorder(postorder,0,postorder.size()-1);
}