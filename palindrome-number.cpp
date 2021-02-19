class Solution {
public:
    bool isPalindrome(int x) {
      if (x < 0)
        return false;
      
      stack<short> digits;
      int xCopy = x;
      
      while (xCopy > 0) {
        digits.push(xCopy % 10);
        xCopy /= 10;
      }
      
      while (x > 0) {
        if (digits.top() != x % 10)
          return false;
        
        x /= 10;
        digits.pop();
      }
      
      return true;
    }
};

