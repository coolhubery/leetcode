/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int getSecondMinimumValue(int val, int left, int right) {

        if (left == -1 && right == -1) {
            return -1;
        } else if (left == -1 && right != val) {
            return right;
        } else if (right == -1 && left != val) {
            return left;
        } else {

            if (val == min(left, right)) {
                if (val == max(left, right)) {
                    return -1;
                } else {
                    return max(left, right);
                }
            } else {
                return min(left, right);
            }
        }
    }

    int findSecondMinimumValue(TreeNode* root) {

        int leftMinVal = -1, rightMinVal = -1, tmpVal = -1, minVal = -1;

        if (root->left && root->right) {
            if (root->left->val == root->val) {
                leftMinVal = findSecondMinimumValue(root->left);
                tmpVal = getSecondMinimumValue(root->val, leftMinVal, root->right->val);
                minVal = getSecondMinimumValue(root->val, tmpVal, minVal);
            }

            if (root->right->val == root->val) {
                rightMinVal = findSecondMinimumValue(root->right);
                tmpVal = getSecondMinimumValue(root->val, rightMinVal, root->left->val);
                minVal = getSecondMinimumValue(root->val, tmpVal, minVal);
            }

            return minVal;
        } else {
            return -1;
        }
    }

    int findSecondMinimumValue_non_recursive(TreeNode* root) {

        std::stack<TreeNode*> treeStack;

        TreeNode *node = root;
        int minVal = -1;

        while (node) {

            if (node->left && node->right) {

                if (node->right->val == root->val) {
                    treeStack.push(node->right);
                }

                if (node->left->val == root->val) {
                    treeStack.push(node->left);
                }

                minVal = getSecondMinimumValue(root->val, minVal, node->right->val);
                minVal = getSecondMinimumValue(root->val, minVal, node->left->val);
            }

            if (treeStack.size() == 0) {
                break;
            }

            node = treeStack.top();
            treeStack.pop();
        }

        return minVal;
    }
};
