//
// Created  on 2020/9/5.
// https://leetcode-cn.com/problems/sliding-window-maximum/
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(k==0) return vector<int>{};
    int len=nums.size();
    vector<int> v(len-k+1,0);
    int max_num=nums[0],max_num_index=0;
    for(int i=1;i<k;++i)
        if(nums[i]>=max_num){
            max_num=nums[i];
            max_num_index=i;
        }
    v[0]=max_num;
    for(int i=k;i<len;++i){
        if(nums[i]>=max_num){
            max_num=nums[i];
            max_num_index=i;
        }else{
            if(max_num_index==i-k){
                ++max_num_index;
                max_num=nums[max_num_index];
                int t=max_num_index;
                for(int j=max_num_index+1;j<t+k;++j)
                    if(nums[j]>=max_num){
                        max_num=nums[j];
                        max_num_index=j;
                    }
            }
        }
        v[i-k+1]=max_num;
    }
    return v;
}