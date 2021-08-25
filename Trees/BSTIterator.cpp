/*
 * =====================================================================================
 *
 *       Filename:  BSTIterator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  25.08.2021 09:07:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Marco Marinò (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        smallest(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if (top->right != NULL)
            smallest(top->right);
            
        return top->val;
    }
    
    
    void smallest(TreeNode* root)
    {
        TreeNode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
