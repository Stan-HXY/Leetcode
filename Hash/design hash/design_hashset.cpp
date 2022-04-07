#include<vector>
#include<list>
using namespace std;

class MyHashSet {
public:
    int KeyRange = 769;
    vector<list<int>> Myhash;
    MyHashSet() {Myhash.resize(100001);}
    
    
    size_t hash_p(int i){
        return i % 5;
    }

    bool search_element(int id, int val){
        for(auto it = Myhash[id].begin(); it != Myhash[id].end(); ++it){
            if(*it == val){
                return true;
            }
        }
        return false;
    }


    void add(int key) {
        if(!search_element(hash_p(key), key)){
            Myhash[hash_p(key)].push_back(key);
        }
    }
    
    void remove(int key) {
        if(search_element(hash_p(key), key)){
            Myhash[hash_p(key)].remove(key);
        }
    }
    
    bool contains(int key) {
        return search_element(hash_p(key), key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */