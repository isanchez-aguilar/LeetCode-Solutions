class Solution {
public:
  static int getValueOfChar(char c) {
    if (c == 'I')
      return 1;
    
    if (c == 'V')
      return 5;
    
    if (c == 'X')
      return 10;
    
    if (c == 'L')
      return 50;
    
    if (c == 'C')
      return 100;
    
    if (c == 'D')
      return 500;
    
    return 1000;
  }
  
  /*
	** Time complexity: O(|s|)
	** Space complexity: O(1)
	*/
	int romanToInt(string s) {
    int answer = 0;
    int currentSum = getValueOfChar(s[0]);
    int prevVal = currentSum;
    const int size = s.size();

    for (int i = 1; i < size; ++i) {
      const int symbolValue = getValueOfChar(s[i]);
      
      if (symbolValue == prevVal) {
        currentSum += symbolValue;
      }
      
      if (symbolValue < prevVal) {
        answer += currentSum;
        currentSum = symbolValue;
      }
      
      if (prevVal < symbolValue) {
        answer += symbolValue - currentSum;
        currentSum = 0;
      }
      
      prevVal = symbolValue;
    }
    
    answer += currentSum;    

    return answer;
  }
};

