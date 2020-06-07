#include <iostream>
using namespace std;

//给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
//所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

string defangIPaddr(string address) {
    for(int i=0;i<address.length();++i){
        if(address.at(i)=='.'){
            address.replace(i,1,"[.]");
            i+=2;
        }
    }
    return address;
}