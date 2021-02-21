class Solution {
public:
    static int findFirstDiff(const vector<int>& nums, int start, int val) {
      const int size = nums.size();
      for (int i = start; i < size; ++i) {
        if (nums[i] != val)
          return i;
      }
      
      return size;
    }
    
		/*
		** Time complexity: O(|nums|)
		** Space complexity: O(1)
		*/
    int removeDuplicates(vector<int>& nums) {
      int lastMoved = 0;
      const int size = nums.size();
      
      for (int i = 0; i < size; ++i) {
        if (i + 1 < size and nums[i] == nums[i + 1]) {
          const int diffIndex = findFirstDiff(nums, i + 2, nums[i]);
          
          i = diffIndex - 1; 
        }
        
        swap(nums[lastMoved], nums[i]);
        ++lastMoved;
      }
      
      nums.resize(lastMoved);
      
      return lastMoved;
    }
}

