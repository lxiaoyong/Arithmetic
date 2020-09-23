//
// Created  on 2020/9/24.
// https://leetcode-cn.com/problems/combination-sum/
#include <vector>
using namespace std;
#include<algorithm>
void cS_backtrack(vector<vector<int>> &result,vector<int>&candidates,vector<int> &v, int target,int current_index,int current_sum){
    for(int i=current_index;i<candidates.size();++i){
        int new_sum = current_sum+candidates[i];
        if(new_sum<target){
            v.push_back(candidates[i]);
            cS_backtrack(result,candidates,v,target,current_index,new_sum);
        }else if(new_sum==target){
            v.push_back(candidates[i]);
            result.push_back(v);
            v.pop_back();
            break;
        }else break;
    }
    if(!v.empty()) v.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> result;
    vector<int> v;
    cS_backtrack(result,candidates,v,target,0,0);
    return result;
}