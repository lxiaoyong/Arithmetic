//
// Created by Liu on 2020/4/5.
//

/*
 * 给定一个没有重复数字的vector，返回其所有可能的全排列
 * 如输入[1,2,3]
 * 返回[ [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1] ]
 * */
#include <vector>
using namespace std;

// used 记录输入的各个数字是否使用过，used在整个递归过程中是同步的。
// in_vector 存储所求的全排列中的各个排列组合，在整个递归过程不同步
void fds(vector<vector<int>> &permute_vector,const vector<int> &num, vector<bool> &used, vector<int> in_vector){
    if(in_vector.size() == num.size()){
        permute_vector.push_back(in_vector);
        return;
    }
    for(int i=0;i<num.size();++i){
        // 当第i个数字未使用时
        if(!used[i]){
            in_vector.push_back(num[i]);
            used[i]= true;
            // 递归寻找后续元素的全排列
            fds(permute_vector, num, used, in_vector);
            /*递归跳出运行到这儿时，说明后续元素的全排列已经找完，第i个数字在此时的in_vector中的位置
             * 应换为used的下一个未使用的数字，故pop,且第i个数字恢复为未使用的状况
            */
            used[i]= false;
            in_vector.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permute_vector;
    vector<bool> used(nums.size(), false);
    vector<int> t;
    fds(permute_vector, nums, used, t);
    return permute_vector;
}
