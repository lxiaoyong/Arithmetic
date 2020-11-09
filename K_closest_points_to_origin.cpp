//
// Created on 2020/11/9.
// https://leetcode-cn.com/problems/k-closest-points-to-origin/
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
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
}