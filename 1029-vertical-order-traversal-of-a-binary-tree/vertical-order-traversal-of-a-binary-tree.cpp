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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; // Use multiset to store values at each position

        // Initialize the queue with the root node and its position (vertical and horizontal)
        queue<pair<TreeNode*, pair<int, int>>> todoList;
        todoList.push({root, {0, 0}});

        while (!todoList.empty()) {
            auto curNode = todoList.front();
            todoList.pop();
            TreeNode* node = curNode.first;
            int vertical = curNode.second.first;
            int horizontal = curNode.second.second;

            nodes[vertical][horizontal].insert(node->val); // Insert the node's value into the multiset

            if (node->left != nullptr)
                todoList.push({node->left, {vertical - 1, horizontal + 1}});

            if (node->right != nullptr)
                todoList.push({node->right, {vertical + 1, horizontal + 1}});
        }

        vector<vector<int>> ans;
        for (auto& p : nodes) {
            vector<int> column;
            for (auto& q : p.second) {
                column.insert(column.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};