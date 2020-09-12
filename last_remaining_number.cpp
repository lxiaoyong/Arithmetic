//
// Created on 2020/9/12.
// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
// https://blog.csdn.net/u011500062/article/details/72855826
int lastRemaining(int n, int m) {
    int index=0;
    for(int i=2;i<=n;++i)
        index=(index+m)%i;
    return index;
}