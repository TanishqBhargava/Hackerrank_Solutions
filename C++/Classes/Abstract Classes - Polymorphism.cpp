#include <list>
#define key first
#define val second
class LRUCache {
    int cp;
    map<int, list<pair<int, int> >::iterator> mp;
    list<pair<int, int> > lru;
public:
    LRUCache(int capacity) : cp(capacity){}
    void set(int key, int val) {
        if(mp.find(key) != mp.end()) {
            mp[key]->key = key;
            mp[key]->val = val;
        }
        else {
            lru.push_front({key, val});
            mp[key] = lru.begin();
            if(lru.size() > cp) {
                mp.erase(lru.back().key);
                lru.pop_back();
            }
        }
    }
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            lru.push_front(*mp[key]);
            lru.erase(mp[key]);
            mp[key] = lru.begin();
            return mp[key]->val;
        }
        else
            return -1;
    }
};
