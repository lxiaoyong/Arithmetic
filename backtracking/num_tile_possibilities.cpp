//
// Created  on 2020/9/22.
//  https://leetcode-cn.com/problems/letter-tile-possibilities/
#include<vector>
#include <string>
#include <algorithm>
using namespace std;
void nTP_backtrack(const string &tiles,int& n ,vector<bool> &used){
    for(int i=0;i<tiles.size();++i){
        // !used[i-1] 排除同层相同元素，不排除递归时的相同元素
        if(i>0 && tiles[i]==tiles[i-1] && !used[i-1]) continue;
        if(!used[i]){
            used[i]=true;
            ++n;
            nTP_backtrack(tiles,n,used);
            used[i]=false;
        }
    }
}
int numTilePossibilities(string tiles) {
    vector<bool> used(tiles.size(), false);
    sort(tiles.begin(),tiles.end());
    int n=0;
    nTP_backtrack(tiles,n,used);
    return n;
}