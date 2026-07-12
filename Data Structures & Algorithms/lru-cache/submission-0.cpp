class LRUCache {
private:
    int size;
    vector<pair<int, int>> cache;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        for (int i=0; i<cache.size(); ++i) {
            if (cache[i].first == key) {
                auto temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp);
                return temp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i=0; i<cache.size(); ++i) {
            if (cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if (cache.size() == size) {
            cache.erase(cache.begin());
        }
        cache.push_back({key, value});
    }
};
