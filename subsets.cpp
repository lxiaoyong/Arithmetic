//
// Created by Liu on 2020/3/30.
//

/*
 * 解决求子集问题，如输入 [1,2,3] ,输出 [ [],[1],[1,2],[1.3],[1,2,3],[2],[2,3],[3] ]
 * */
#include <vector>
#include <queue>
using namespace std;

// 下列注释解释，输入为 [1,2,3]
/*
 * select 函数中sub_queue的存储过程如下（subsets 函数第一轮循环的情况）
 * [1]
 * [1],[1,2],[1.3]
 * [1,2],[1.3]
 * [1,2],[1.3],[1,2,3]
 * [1.3],[1,2,3]
 * [1,2,3]
 *
 * */
void select(vector<vector<int>> & subset_vector, vector<int> &nums, int index){

    queue<int> q; // 记录子集中的vector<int> 最后一个数字的位置
    q.push(index);

    vector<int> sub_vector; //记录子集中的一个vector
    sub_vector.push_back(nums[index]);

    queue<vector<int>> subset_queue; // 该处使用队列，便于举出所有组合
    subset_queue.push(sub_vector);

    while(!subset_queue.empty()){   //队列不空时，说明以 nums[index] 数字开头的子集没有列举完
        /*
         * 当 subset_queue 的首元素为[1]时，队列添加[1,2]，[1,3],然后 pop 掉[1],按此时的首元素[1,2]来寻找组合
         * */
        for(int i=q.front()+1;i<nums.size();++i){
            vector<int> new_sub_vector=subset_queue.front();
            new_sub_vector.push_back(nums[i]);
            subset_queue.push(new_sub_vector);
            q.push(i);//记录此时添加的vector的最后一个数字处于nums的位置，下次开始循环时从下一个数字开始
        }
        subset_vector.push_back(subset_queue.front());//pop前push到 vector<vector<int>> 中
        subset_queue.pop();
        q.pop();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subset;
    vector<int> null_vector;    // push 空的vector
    subset.push_back(null_vector);
    /*
     * 第一轮寻找以 1 开头的子集 即[1],[1,2],[1.3],[1,2,3]
     * 第二轮为 [2],[2,3]
     * 第三轮为 [3]
     * */
    for(int i=0;i<nums.size();++i){
        select(subset, nums, i);
    }
    return subset;
}
