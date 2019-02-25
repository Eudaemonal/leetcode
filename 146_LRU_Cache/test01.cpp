#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <utility>

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end()) return -1;
        cache.splice(cache.begin(), cache, hash[key]);

        return hash[key]->second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
			hash[key]->second = value;
            return;
		}
        else if(cache.size() == capacity){
            int k = cache.back().first;
            cache.pop_back();
            hash.erase(k);
        }
        cache.push_front(std::make_pair(key, value));
        hash.emplace(key, cache.begin());
    }

private:
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash;
    std::list<std::pair<int, int>> cache;
    int capacity;
};

int main(int argc, char *argv[]){
    try{
        LRUCache cache( 2 /* capacity */ );

        cache.put(1, 1);
        cache.put(2, 2);
        cache.get(1);       // returns 1
        cache.put(3, 3);    // evicts key 2
        cache.get(2);       // returns -1 (not found)
        cache.put(4, 4);    // evicts key 1
        cache.get(1);       // returns -1 (not found)
        cache.get(3);       // returns 3
        cache.get(4);       // returns 4

        return EXIT_SUCCESS;
    }catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
