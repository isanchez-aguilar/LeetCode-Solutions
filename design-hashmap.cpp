class Store {
  public:
    Store() {}  
    
    int get(const int& value) const {
      for (const pair<int, int>& keyValue : values) {
        if (keyValue.first == value) {
          return keyValue.second;
        } 
      }
      
      return -1;
    } 
    
    void put(const int& key, const int& value) {
      for (pair<int, int>& keyValue : values) {
        if (keyValue.first == key) {
          keyValue.second = value; 
          return;
        } 
      }
      
      values.push_back({ key, value }); 
    }
  
    void remove(const int& key) {
      values.remove_if([key](const pair<int, int>& keyValue){
        return keyValue.first == key; 
      });
    }
  private:
    list< pair<int, int> > values;
};

class MyHashMap {
public: 
  static const int STORE_SIZE = 1000000;
  vector<Store>values;
  
  /** Initialize your data structure here. */
  MyHashMap(): values(STORE_SIZE) {
  }
  
  static int hashFunction(const int& value) {
    return value % STORE_SIZE; 
  }
    
  /** value will always be non-negative. */
  void put(int key, int value) {
    values[hashFunction(key)].put(key, value);
  }
    
  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    return values[hashFunction(key)].get(key); 
  }
    
  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    values[hashFunction(key)].remove(key);
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
 