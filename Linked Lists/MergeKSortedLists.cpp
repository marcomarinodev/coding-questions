//
//  main.cpp
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/merge-k-sorted-lists/
// Asked By: Facebook, Amazon, Google, Microsoft, Oracle, Bloomberg,
// IXL, Adobe, Uber, Wish, Apple, LinkedIn, VMWare, Yahoo, Walmart Labs,
// Salesforce, Samsung and Mathworks

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		
		for (ListNode *head: lists) {
			while (head != nullptr) {
				minHeap.push(head->val);
				head = head->next;
			}
		}
		
		ListNode *mergedList = new ListNode(-1);
		ListNode *head = mergedList;
		
		while(!minHeap.empty()) {
			ListNode *value = new ListNode(minHeap.top());
			head->next = value;
			head = head->next;
			minHeap.pop();
		}
		
		return mergedList->next;
		
	}
	
	void test() {
		
		vector<ListNode *> test1;
		
		test1.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
		test1.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
		test1.push_back(new ListNode(2, new ListNode(6)));
		
		vector<ListNode *> test2;
		
		test2.push_back(nullptr);
		test2.push_back(nullptr);
		
		vector<ListNode *> test3;
		
		test3.push_back(nullptr);
		test3.push_back(new ListNode(1));
		
		ListNode *mergedTest1 = mergeKLists(test1);
		ListNode *mergedTest2 = mergeKLists(test2);
		ListNode *mergedTest3 = mergeKLists(test3);
		
		ListNode *current = mergedTest1;
		
		while (current != nullptr) {
			cout << current->val << endl;
			current = current->next;
		}
		
		cout << "Test passed!" << endl;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

