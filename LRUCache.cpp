//
// Created by Liu on 2020/4/15.
//
#include <map>
#include <list>
using namespace std;

/*
 * 设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 *获取数据 get(key) - 如果key存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 *写入数据 put(key, value) , 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。
 * 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 * */
class LRUCache {
public:
    LRUCache(int capacity) {
        cache_capacity=capacity;
        size=0;
    }

    int get(int key) {
        if(cache.find(key)!=cache.end()) {
            key_list.remove(key);
            key_list.push_front(key);
            return cache.find(key)->second;
        }
        else return -1;
    }

    void put(int key, int value) {
        //若缓存区满了
        if(size==cache_capacity){
            //若密钥已经存在，只需要更换值，不需删除最久未用的值
            if(cache.find(key)!=cache.end()){
                key_list.remove(key);
                key_list.push_front(key);
                cache[key]=value;
            }
                //否则，需要删除最久未用的值
            else{
                cache.erase(key_list.back());
                key_list.pop_back();
                key_list.push_front(key);
                cache.insert({key,value});
            }
        } else{
            if(cache.find(key)!=cache.end()){
                key_list.remove(key);
                key_list.push_front(key);
                cache[key]=value;
            } else{
                key_list.push_front(key);
                cache.insert({key,value});
                ++size;
            }
        }
    }

private:
    map<int,int> cache;
    list<int> key_list;
    int cache_capacity,size;
};