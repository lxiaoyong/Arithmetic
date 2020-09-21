//
// Created  on 2020/9/21.
// https://leetcode-cn.com/problems/subsets/
#include<vector>
using namespace std;
void backtrack(int index,vector<int >& nums,
               vector<vector<int>> &result,vector<int> &t){
    for(int i=index;i<nums.size();++i){
        t.push_back(nums[i]);
        result.push_back(t);
        backtrack(i+1,nums,result,t);
        t.pop_back();
    }

}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int >> result{{}};
    vector<int> t;
    backtrack(0,nums,result,t );
    return result;
}