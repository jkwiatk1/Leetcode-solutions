#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if((root->left==NULL)&&(root->right==NULL)){
            return 1;
        }
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return std::max(maxLeft, maxRight) + 1;
    }
};

int main()
{
    TreeNode n5(5, nullptr, nullptr);
    TreeNode n15(15, &n5, nullptr);
    TreeNode n7(7, nullptr, nullptr);
    TreeNode n20(20, &n15, &n7);
    TreeNode n9(9, nullptr, nullptr);
    TreeNode n3(3, &n9, &n20);

    Solution solution;
    std::cout << solution.maxDepth(&n3);

    return 0;
}