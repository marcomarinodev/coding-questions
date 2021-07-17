//
//  main.cpp
//
//  Created by Marco Marinò on 16/07/21.
// https://leetcode.com/problems/range-sum-of-bst/

// Asked by: Amazon, Facebook, Microsoft and Adobe

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
	
	/**
	 Complexity of this algorithm:
	 
	 T(n) = 2T(n/2) = 2(2T(n/4) = 2^3 * T(n/2^3) = 2^i*T(n/2^i)==> n/2^i = 1 <==> 2^i = n <==> log_2 (n) = i
	 ==> 2^log_2(n) * T(1) ==> O(n)
	 
	 */
	int rangeSumBST(TreeNode* root, int low, int high) {
		
		if (root == nullptr) return 0;
			
		if (root->val < low) {
			return rangeSumBST(root->right, low, high);
		}
		
		if (root->val > high) {
			return rangeSumBST(root->left, low, high);
		}
		
		return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
	}
	
	void test() {
		TreeNode *test1 = new TreeNode(10, new TreeNode(5, new TreeNode(3), new TreeNode(7)),  new TreeNode(15, nullptr, new TreeNode(18)));
		
		TreeNode *test2 = new TreeNode(10, new TreeNode(5, new TreeNode(3, new TreeNode(1), nullptr), new TreeNode(7, new TreeNode(6), nullptr)),  new TreeNode(15, nullptr, new TreeNode(18)));
		
		assert(32 == rangeSumBST(test1, 7, 15));
		assert(23 == rangeSumBST(test2, 6, 10));
		
		cout << "Test passed!" << endl;
	}
};

int main(int argc, const char * argv[]) {
	
	Solution * sol = new Solution();
	
	sol->test();
	
	return 0;
}

