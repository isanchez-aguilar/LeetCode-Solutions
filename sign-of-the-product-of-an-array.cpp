class Solution {
public:
    /*
    ** Time complexity: O(n)
    ** Space complexity: O(1)
    */
    int arraySign(const vector<int>& nums) const {
      int negativeNumbers = 0;
      
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
          return 0; 
        }
        
        if (nums[i] < 0)
          ++negativeNumbers;   
      } 
      
      return negativeNumbers % 2 == 0?1:-1;
    }
  
};