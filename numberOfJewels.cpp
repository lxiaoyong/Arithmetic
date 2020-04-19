//
// Created by Liu on 2020/4/19.
//

#include <hash_set>
using namespace std;
/*
 * 给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，
 * 你想知道你拥有的石头中有多少是宝石。
 * J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 * */

int numJewelsInStones(string J, string S) {
    if(J.empty() || S.empty()) return 0;
    __gnu_cxx::hash_set<char > type;
    for(char ch:J){
        type.insert(ch);
    }
    int number=0;
    for(char ch:S){
        if(type.find(ch)!=type.end())
            ++number;
    }
    return number;
}