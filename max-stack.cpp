class MaxStack {
public:
  /** initialize your data structure here. */
  MaxStack() {}

  /*
  ** Complexity time: O(log2 n)
  */
  void push(int x) {
    values.push_back(x);
    valueIterator[x].push_back(--end(values));
  }
  /*
  ** Complexity time: O(log2 n)
  */
  int pop() {
    const int currentValue = values.back();
    
    values.pop_back();
    valueIterator[currentValue].pop_back();
    removeIfIsEmptyValue(currentValue);
    
    return currentValue;
  }

  /*
  ** Complexity time: O(1)
  */
  int top() {
    return values.back();
  }
  /*
  ** Complexity time: O(1)
  */
  int peekMax() {
    const int currentMax = getLastMapValue()->first;
    return currentMax;
  }

  /*
  ** Complexity time: O(log2 n)
  */
  int popMax() {
    const int currentMax = peekMax();
    
    list< list<int>::iterator >& iteratorsValue = getLastMapValue()->second; 
    list<int>::iterator maxIterator = iteratorsValue.back();
    iteratorsValue.pop_back();
    
    
    values.erase(maxIterator);
    removeIfIsEmptyValue(currentMax);
    
    return currentMax; 
  }
private:
  list<int> values;
  map<int, list< list<int>::iterator > > valueIterator;
                              
  map<int, list< list<int>::iterator > >::iterator getLastMapValue() {
    return --end(valueIterator); 
  }
  
  void removeIfIsEmptyValue(int x) {
    if(valueIterator[x].empty()) {
      valueIterator.erase(x); 
    }
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 *
**/