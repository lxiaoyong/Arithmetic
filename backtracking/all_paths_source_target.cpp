//
// Created on 2020/10/9.
// https://leetcode-cn.com/problems/all-paths-from-source-to-target/
#include<vector>
using namespace std;

void aPST_backtrack(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int>& path, int row){
    path.push_back(row);
    if(row == graph.size()-1) {
        result.push_back(path);
        path.pop_back();
        return;
    }
    for(int p:graph[row])
        aPST_backtrack(graph, result, path, p);
    path.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    aPST_backtrack(graph, result, path, 0);
    return result;
}