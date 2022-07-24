class MyHashMap {
public:
    /** Initialize your data structure here. */
    
    vector<list<pair<int, int>>> m;
    int size = 1e2;
    MyHashMap() {
        m.resize(size);
    }
    
    int hash(int key){
        
        return key%size;
    }
    
    auto search(int key){
        
        int i = hash(key);
        list<pair<int,int>> :: iterator it = m[i].begin();
        
        while(it!=m[i].end()){
            
            if(it->first==key) return it;
            it++;
        }
        return it;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        auto it = search(key);
        int i = hash(key);
        if(it!=m[i].end()) it->second = value;
        else{
        
        m[i].push_back({key,value});
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
        int val;
        int i = hash(key);
        auto it = search(key);
        if(it!=m[i].end()){
            val = it->second;
        }
        else{
            val = -1;
        }
        
        return val;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
        if(get(key)==-1) return;
        int i = hash(key);
        m[i].erase(search(key));
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */