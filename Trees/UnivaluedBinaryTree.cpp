#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isUTree(TreeNode *root, int number) {
        
        if (root == nullptr) return true;
        
        if (root->val != number) return false;
        
        return isUTree(root->left, number) && isUTree(root->right, number);
        
    }
    
    bool isUnivalTree(TreeNode* root) {
        
        return isUTree(root, root->val);;
    }
};



int main(int argc, const char * argv[]) {
    
    Solution *sol = new Solution();
    
    TreeNode *test1 = new TreeNode(3);
    
    TreeNode *test2 = new TreeNode(1, new TreeNode(1), new TreeNode(2));
    
    TreeNode *test3 = new TreeNode(5, nullptr, new TreeNode(5));
    
    assert(sol->isUnivalTree(test1) == true);
    
    assert(sol->isUnivalTree(test2) == false);
    
    assert(sol->isUnivalTree(test3) == true);
    
    cout << "Test passed!" << endl;
    
    return 0;
}

