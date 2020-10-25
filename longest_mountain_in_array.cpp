//
// Created on 2020/10/25.
//
#include <vector>
using namespace std;
int longestMountain(vector<int>& A) {
    int A_size = A.size();
    if(A_size<3) return 0;
    int B_size = 0,max_B_size = 0;
    int index = 0;
    bool inc = false,dec = false;
    while(index<A_size){
        ++B_size;
        int j = index+1;
        while(j<A_size){
            if(A[j]>A[index]){
                ++B_size;index=j;++j;
                inc = true;
            }else if(inc && A[j]<A[index]){ // 此时 A[index] 为山顶
                ++B_size;
                dec = true;
                for(int k=j+1;k<A_size;++k,++j){
                    if(A[k]<A[j]) ++B_size;
                    else break;
                }
                break;
            }else break;
        }
        index = j;
        if(dec && B_size>2) max_B_size = max(max_B_size,B_size);
        inc = false;dec = false;
        B_size = 0;
    }
    return max_B_size;
}