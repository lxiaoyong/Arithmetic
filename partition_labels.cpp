//
// Created by 刘晓涌 on 2020/10/23.
//
#include<vector>
#include<string>
using namespace std;
vector<int> partitionLabels(string S) {
    if(S.empty()) return {};
    vector<int> first(26,-1);
    vector<int> last(26,-1);
    int len = S.size();
    for(int i=0;i!=len;++i){
        int index = S[i]-'a';
        if(first[index] == -1) first[index]=i;
        last[index]=i;
    }
    vector<int> result;
    result.push_back(last[S[0]-'a']);
    for(int i=1;i!=len;++i){
        int re_last = *(--result.end());
        if(first[S[i]-'a']>re_last) result.push_back(last[S[i]-'a']);
        else  *(--result.end()) = max(re_last,last[S[i]-'a']);
    }
    int nums = result.size();
    for(int i=nums-1;i!=0;--i) result[i] -=result[i-1];
    ++result[0];
    return result;
}
/*
 *
    vector<int> partitionLabels(string S) {
        vector<int> char_last_index(26, -1);
        for (int i = 0; i < S.size(); i++) {
            char_last_index[S[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        int size = S.size();
        for (int i = 0; i < size; i++) {
            end = max(end, char_last_index[S[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
 * */