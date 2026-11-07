class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> cache;
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void recentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }

    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        recentlyUsed(key);
        return cache[key].second;
    }

    // Insert or update key-value
    void put(int key, int value) {
        // If key already exists
        if(cache.find(key) != cache.end()) {
            cache[key].second = value;
            recentlyUsed(key);
        }
        else {
            // Insert new key at front
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
        }

        // Remove least recently used key
        if(cache.size() > capacity) {
            int lru = dll.back();
            dll.pop_back();
            cache.erase(lru);
        }
    }
};