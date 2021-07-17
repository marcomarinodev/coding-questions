//
//  main.cpp
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Asked By: Google, Amazon, Apple, LinkedIn and Yahoo

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
	
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);
		
		return max(leftDepth, rightDepth) + 1;
	}
	
	void test() {
		TreeNode *test1 = new TreeNode(3, new TreeNode(9),  new TreeNode(20, new TreeNode(15), new TreeNode(7)));
		
		TreeNode *test2 = new TreeNode(1, nullptr, new TreeNode(2));
		
		TreeNode *test3 = nullptr;
		
		TreeNode *test4 = new TreeNode(0);
		
		assert(3 == maxDepth(test1));
		assert(2 == maxDepth(test2));
		assert(0 == maxDepth(test3));
		assert(1 == maxDepth(test4));
		
		cout << "Test passed!" << endl;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

