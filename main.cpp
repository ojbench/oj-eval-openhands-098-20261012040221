#include <iostream>
#include <vector>
#include <algorithm>

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
    // Function to build BST from level order traversal
    TreeNode* buildBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            insertNode(root, nums[i]);
        }
        
        return root;
    }
    
    // Helper function to insert a node into BST
    void insertNode(TreeNode* root, int val) {
        if (val < root->val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
            } else {
                insertNode(root->left, val);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
            } else {
                insertNode(root->right, val);
            }
        }
    }
    
    // Function to get k-th largest element in BST
    int kthLargest(TreeNode* root, int k) {
        std::vector<int> values;
        inorderTraversal(root, values);
        
        // Sort in descending order to get k-th largest
        std::sort(values.begin(), values.end(), std::greater<int>());
        
        return values[k-1];
    }
    
    // Inorder traversal to collect all values
    void inorderTraversal(TreeNode* root, std::vector<int>& values) {
        if (root == nullptr) return;
        
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }
    
    // Clean up memory
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    std::vector<int> nums(7);
    int k;
    
    // Read 7 node values
    for (int i = 0; i < 7; i++) {
        std::cin >> nums[i];
    }
    
    // Read k
    std::cin >> k;
    
    Solution solution;
    TreeNode* root = solution.buildBST(nums);
    int result = solution.kthLargest(root, k);
    
    std::cout << result << std::endl;
    
    // Clean up memory
    solution.deleteTree(root);
    
    return 0;
}
