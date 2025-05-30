#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if(it == map.end()) {
            return -1;
        }
        
        // 移动到链表头部
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        
        if(it != map.end()) {
            // 键已存在，更新值并移动到头部
            cache.erase(it->second);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
            return;
        }
        
        // 键不存在，需要插入
        if(cache.size() == capacity) {
            // 淘汰最久未使用的
            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }
        
        // 插入新键值对
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // 返回 1
    cache.put(3, 3);               // 淘汰键2
    cout << cache.get(2) << endl;  // 返回 -1
    cache.put(1, 4);               // 更新键1的值
    cout << cache.get(1) << endl;  // 返回 4
    cout << cache.get(3) << endl;  // 返回 3
}