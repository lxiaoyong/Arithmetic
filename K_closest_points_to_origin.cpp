//
// Created on 2020/11/9.
// https://leetcode-cn.com/problems/k-closest-points-to-origin/
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
// 快速选择
void fast_sort(vector<pair<int,int>>& dic_pow,int left,int right,int k){
    if(left>right) return;
    auto flag = dic_pow[left];
    int start = left,end = right;
    while(left<right){
        while(left<right && dic_pow[right].first>flag.first ) --right;
        if(left<right) dic_pow[left] = dic_pow[right];
        while(left<right && dic_pow[left].first<=flag.first) ++left;
        if(left<right) dic_pow[right] = dic_pow[left];
    }
    dic_pow[left]=flag;
    if(left == k-1) return;
    else if(left<k-1) fast_sort(dic_pow,left+1,end,k);
    else fast_sort(dic_pow,start,left-1,k);
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    int size = points.size();
    vector<pair<int,int>> dic_pow(size);
    for(int i=0;i<size;++i)
        dic_pow[i]=make_pair(pow(points[i][0],2)+pow(points[i][1],2),i);
    fast_sort(dic_pow,0,size-1,K);
    vector<vector<int>> result(K);
    for(int i=0;i<K;++i)
        result[i]=points[dic_pow[i].second];
    return result;
}

/*  优先队列
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<long,int>> q;
    int size = points.size();
    for(int i=0;i<size;++i){
        long dis = pow(points[i][0],2)+pow(points[i][1],2);
        if(q.size()<K) q.push(make_pair(dis,i));
        else{
            if(q.top().first>dis){
                q.pop();
                q.push(make_pair(dis,i));
            }
        }
    }
    vector<vector<int>> result;
    while(!q.empty()){
        result.push_back(points[q.top().second]);
        q.pop();
    }
    return result;
}*/
