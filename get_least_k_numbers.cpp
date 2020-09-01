//
// Created  on 2020/9/1.
// https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/
#include <vector>
using namespace std;
// 快速选择
int get_index(vector<int> & v,int left,int right){
    int i=v[left];
    while(left<right){
        while(left<right && v[right]>=i) --right;
        if(left<right) v[left]=v[right];
        while(left<right && v[left]<i) ++left;
        if(left<right) v[right]=v[left];
    }
    v[left]=i;
    return left;
}
void fast_choose(vector<int>& arr,int left,int right, int k) {
    if(left<right){
        int i=get_index(arr,left,right);
        if(i+1==k) return;  // 一旦找到前k个，结束寻找
        if(i>k) fast_choose(arr,left,i-1,k);
        else fast_choose(arr,i+1,right,k);
    }
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> result;
    if(k==0 || (int )arr.size()==0) return result;
    fast_choose(arr,0,(int )arr.size()-1,k);
    for(int i=0;i<k;++i) result.push_back(arr[i]);
    return result;
}