string toStringNumber(int x, bool reverseString = false) {
	bool firstNonZero = false;
	string number = "";
		
	while (x != 0) {
		int withoutLastDigit = x / 10 * 10; 
		short lastDigit = (short)(x - withoutLastDigit);

		if (lastDigit < 0)
			lastDigit = -lastDigit;
		
		if (firstNonZero or lastDigit != 0) {
			firstNonZero = true;
			number += char(lastDigit + '0');
    }

		x /= 10;
	}
  
  if (reverseString)
    reverse(number.begin(), number.end());

	return number;
}

string minNumber = toStringNumber(INT_MIN, true);
string maxNumber = toStringNumber(INT_MAX, true);


class Solution {
public:
	/*
	** Time complexity: O(log2(x))
	** Space complexity: O(log2(x))
	*/
  int reverse(int x) {
		if (x == 0)
			return 0;

		const string number = toStringNumber(x);

		if (x > 0 and isGreater(number, maxNumber)) 
			return 0; 

		if (x < 0 and isGreater(number, minNumber))
			return 0;
		
		int reversedNumber = toInteger(number);

		if (x < 0)
			return -reversedNumber;

		return reversedNumber;
	}

	static bool isGreater(const string& a, const string& b) {
		if (a.size() < b.size())
			return false;

		if (a.size() > b.size())
			return true;
    
		return a > b;
	}

	static int toInteger(const string& number) {
		int solution = 0;

		for (const char& digit : number) {
			solution *= 10;

			solution += (int)digit - '0';
		}

		return solution;
	}
};

