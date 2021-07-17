//
//  main.cpp
//  Split a String in Balanced Strings
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/defanging-an-ip-address/

/**
 Asked by: Apple, Facebook and Adobe
 */

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
	string defangIPaddr(string address) {
		string defangedIPaddr("");
		
		for (int i = 0; i < address.length(); i++) {
			if (address[i] != '.') {
				defangedIPaddr.push_back(address[i]);
			} else {
				defangedIPaddr.push_back('[');
				defangedIPaddr.push_back('.');
				defangedIPaddr.push_back(']');
			}
		}
		
		return defangedIPaddr;
	}
	
	void test() {
		
		string test1("1.1.1.1");
		string test2("255.100.50.0");
		
		assert("1[.]1[.]1[.]1" == defangIPaddr(test1));
		assert("255[.]100[.]50[.]0" == defangIPaddr(test2));
		
		cout << "Test passed !" << endl;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

