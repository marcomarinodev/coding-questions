//
//  main.cpp
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/split-a-string-in-balanced-strings/

/**
 This problem was asked in Google coding interviews
 */

#include <iostream>

using namespace std;

class Solution {
public:
	 int balancedStringSplit(string s) {
		 int counter = 0;
		 int l_sequence = 0;
		 int r_sequence = 0;

		 for (string::size_type i = 0; i < s.size(); i++) {
			 
			 if (s[i] == 'L') {
				 l_sequence++;
			 } else {
				 r_sequence++;
			 }
			 
			 if (l_sequence == r_sequence) {
				 counter++;
				 l_sequence = 0;
				 r_sequence = 0;
			 }
		 }
		 
		 return counter;
	 }
	
	void test() {
		int test1 = balancedStringSplit("RLRRLLRLRL");
		int test2 = balancedStringSplit("RLLLLRRRLR");
		int test3 = balancedStringSplit("LLLLRRRR");
		int test4 = balancedStringSplit("RLRRRLLRLL");
		
		assert(test1 == 4);
		assert(test2 == 3);
		assert(test3 == 1);
		assert(test4 == 2);
		
		cout << "Test passed!" << endl;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

