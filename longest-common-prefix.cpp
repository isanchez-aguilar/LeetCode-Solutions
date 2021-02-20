class Solution {
public:
		/*
		** Time complexity: O(|strs|)
		** Space complexity: O(1)
		*/
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.size() == 0)
        return "";
      
      if (strs.size() == 1)
        return strs[0];
        
      string prefix = "";
      char currChar;
      
      for (int i = 0; i < strs[0].size(); ++i) {
        currChar = strs[0][i];
        
        for (int j = 1; j < strs.size(); ++j) {
          if (strs[j].size() < i or strs[j][i] != currChar)
            return prefix;
        }
        
        prefix += currChar;
      } 
      
      return prefix;
    }
};

