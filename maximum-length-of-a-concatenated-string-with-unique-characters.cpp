namespace SolutionUtils {
  unordered_map< int, unordered_map<int, int> > memo;
  int presentCharactersWord[17];
  
  int getPresentCharacters(const string& s) {
    int ans = 0;
    
    for (const char& c : s) {
      const int position = int(c) - int('a');
      
      if (ans & (1 << position)) {
        return -1; 
      }
      
      ans |= (1 << position);
    }
    
    return ans;
  }
}

class Solution {
public:
  /*
  ** Time Complexity: O(2^|arr| * |arr|)
  ** Space Complexity: O(2^|arr| * |arr|)
  */
  int maxLength(const vector<string>& arr) {
    lengths = vector<int>(arr.size());
    SolutionUtils::memo.clear(); 
    
    for (int i = 0; i < arr.size(); ++i) {
      SolutionUtils::presentCharactersWord[i] = SolutionUtils::getPresentCharacters(arr[i]); 
      lengths[i] = arr[i].size();
    }
    
    return getMaxConcatenatedString(0, arr.size() - 1); 
  }
  
  int getMaxConcatenatedString(const int& usedCharacters, const int& currentWordIndex) {
    if (currentWordIndex == -1)
      return 0;
    
    if (SolutionUtils::memo.count(usedCharacters) == 1 and SolutionUtils::memo[usedCharacters].count(currentWordIndex) == 1)
      return SolutionUtils::memo[usedCharacters][currentWordIndex];
    
    int ans = 0;
    
    const int& currentWordCharacters = SolutionUtils::presentCharactersWord[currentWordIndex];
    
    if (currentWordCharacters != -1 and not (usedCharacters & currentWordCharacters)) {
      ans = lengths[currentWordIndex] + getMaxConcatenatedString(usedCharacters | currentWordCharacters, currentWordIndex - 1);
    }
    
    ans = max(ans, getMaxConcatenatedString(usedCharacters, currentWordIndex - 1));
    
    return SolutionUtils::memo[usedCharacters][currentWordIndex] = ans;
  }
private:
  vector<int> lengths;
};
