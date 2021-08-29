class Solution {
public:
  static const int lastDigitMax = INT_MAX % 10;
  static const int lastDigitMin = INT_MIN % 10;
    
  static bool isOverflowSum(int a, int b) {
    // Positive integer
    if (a > INT_MAX / 10 or (a == INT_MAX / 10 and b > lastDigitMax))
      return true;
    
    // Negative integer
    if (a < INT_MIN / 10 or (a == INT_MIN / 10 and b < lastDigitMin))
      return true;
    
    return false;
  }
 
  /*
  ** Time complexity: O(log10 x)
  ** Space complexity: O(1)
  */
  int reverse(int x) {
    int result = 0;
    
    while (x != 0) {
      const int lastDigit = x % 10;
      x /= 10;
      
      if (isOverflowSum(result, lastDigit))
        return 0;
      
      result = 10 * result + lastDigit;
    }
    
    return result;
  }
};
