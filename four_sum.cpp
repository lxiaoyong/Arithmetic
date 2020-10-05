//
// Created  on 2020/10/5.
//  https://leetcode-cn.com/problems/4sum/
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int size = nums.size();
    if(size<4) return result;
    sort(nums.begin(),nums.end());
    int max_a=size-3,max_b=max_a+1;
    for(int a=0;a<max_a;++a){
        if(a>0 && nums[a]==nums[a-1]) continue;
        int a_val = nums[a];
        // 剪枝
        if(a_val+nums[a+1]+nums[a+2]+nums[a+3]>target) break;
        if(a_val+nums[size-3]+nums[size-2]+nums[size-1]<target) continue;

        for(int b=a+1;b<max_b;++b){
            if(nums[b]==nums[b-1] && b-1!=a) continue;
            int b_val = nums[b];
            // 剪枝
            if(a_val+b_val+nums[b+1]+nums[b+2]>target) break;
            if(a_val+b_val+nums[size-2]+nums[size-1]<target) continue;
            // 双指针
            int c=b+1,d=size-1;
            while(c<d){
                int c_val = nums[c] , d_val = nums[d];
                int _sum = a_val+b_val+c_val+d_val;
                if(_sum==target){
                    vector<int> v{a_val,b_val,c_val,d_val};
                    result.push_back(v);
                    ++c;
                    --d;
                    while(c<d && nums[c-1]==nums[c]) ++c;
                    while(c<d && nums[d+1]==nums[d]) --d;
                }
                else if(_sum<target) ++c;
                else    --d;
            }
        }
    }
    return result;
}