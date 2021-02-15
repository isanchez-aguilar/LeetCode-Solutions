class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> solution(2);
      const int size = (int)nums.size();
      unordered_map<int, int> previousValues;
      
      for (int i = 0; i < size; ++i) {
        const int remaining = target - nums[i];
        
        if (previousValues.count(remaining) > 0) {
          solution[0] = i;
          solution[1] = previousValues[remaining];
          break;
        }
        
        previousValues[nums[i]] = i;
      } 
      
      return solution;
    }
};
