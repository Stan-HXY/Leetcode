#include<map>
#include<vector>
#include<utility>
using namespace std;

class MyHashMap {
public:
    vector<pair<int, int>> Hashmap;
    MyHashMap() {
        Hashmap.resize(769);
    }
    
    size_t hash_p(int i){
        return i % 5;
    }
    
    void put(int key, int value) {
        for(auto it : Hashmap){
            if(it.first == key){
                it.second = value;
                return;
            }  
        }
        Hashmap.push_back({key, value}); // insert a PAIR, just use { first, second }
    }
    
    int get(int key) {
        for(auto it : Hashmap){
            if(it.first == key){
                return it.second;
            }
        }
        return -1;

    }
    
    void remove(int key) {
        if(get(key)!= -1){
            for(auto it = Hashmap.begin(); it != Hashmap.end(); ++it){
                if(it->first==key){
                    Hashmap.erase(it);
                }
            }
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */