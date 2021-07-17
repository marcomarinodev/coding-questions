//
//  main.cpp
//  Split a String in Balanced Strings
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <string.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
	 ListNode* reverseList(ListNode* head) {
		 
		 if (head == nullptr)
			 return nullptr;
		 
		 ListNode *p = nullptr;
		 ListNode *c = head;
		 ListNode *n = head->next;
		 
		 while (c != nullptr) {
			 c->next = p;
			 p = c;
			 c = n;
			 
			 if (n != nullptr)
				 n = n->next;
		 }
		 
		 return p;
	 }
	
	void test() {
		ListNode *test1H = new ListNode(1 ,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
		
		ListNode *test2H = new ListNode(1, new ListNode(2, nullptr));
		
		ListNode *test3H = nullptr;
		
		test1H = reverseList(test1H);
		
		test2H = reverseList(test2H);
		
		test3H = reverseList(test3H);
		
		assert("54321" == printList(test1H));
		
		assert("21" == printList(test2H));
		
		assert("" == printList(test3H));
		
		cout << "\nTest passed!" << endl;
		
	}
	
	string printList(ListNode *head) {
		string result = "";
		ListNode *current = head;
		
		while (current != nullptr) {
			string current_value = to_string(current->val);
			result.append(current_value);
			current = current->next;
		}
		
		return result;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

