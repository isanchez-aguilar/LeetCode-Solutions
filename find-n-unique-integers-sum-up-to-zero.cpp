class Solution {
public:
    /*
    ** Time complexity: O(n)
    ** Space complexity: O(1)
    */
    vector<int> sumZero(int n) {
      vector<int> solution(n);
      const int firstValue = -n / 2;
      
      for (int i = 0; i < n; ++i) {
        int currentValue = firstValue + i;
        
        if (currentValue >= 0 and n % 2 == 0)
          ++currentValue;
        
        solution[i] = currentValue;
      }
      
      return solution; 
    }
};
