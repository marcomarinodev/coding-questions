#include <iostream>

// 129

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
    
    int sumSimple(TreeNode *root, int s) {
        
        if (root == nullptr) return 0;
        
        if (root->left == nullptr && root->right == nullptr) return (s*10) + root->val;
        
        return sumSimple(root->left, s*10 + root->val) + sumSimple(root->right, s*10 + root->val);
        
    }
    
    int sumNumbers(TreeNode* root) {
    
        return sumSimple(root, 0);
        
    }
};

int main(int argc, const char * argv[]) {
    
    Solution *sol = new Solution();
    
    TreeNode *test1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    
    TreeNode *test2 = new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0));
    
    cout << sol->sumNumbers(test1) << endl;
    cout << sol->sumNumbers(test2) << endl;
    
    cout << "Test passed!";
    
    return 0;
}

