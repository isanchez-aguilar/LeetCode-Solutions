map<char, char> open = {
  {')', '('},
  {']', '['},
  {'}', '{'}
};

class Solution {
public:
    bool isValidClose(char c, const stack<char>& lastParentheses) {
      if (lastParentheses.empty())
        return false;
      
      if (open.count(c) and lastParentheses.top() == open[c])
        return true;
      
      return false;
    }
  
    /*
		** Time complexity: O(|s|)
		** Space complexity: O(|s|)
		*/
		bool isValid(string s) {
      stack<char> lastParentheses;
      
      for (const char& c : s) {
        if (open.count(c) == 0) {
          lastParentheses.push(c);
          continue;
        }
        
        if (isValidClose(c, lastParentheses)) {
          lastParentheses.pop();
          continue;
        }
        
        return false;
      }
      
      return lastParentheses.empty();
    }
};

