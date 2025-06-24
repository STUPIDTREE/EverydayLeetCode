#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* left, TreeNode* right) : val(v), left(left), right(right) {}
};

TreeNode* ArrayToTree(vector<string>& array, int index) {
    if(index >= array.size() || array[index] == "null") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(array[index]));
    root->left = ArrayToTree(array, index * 2 + 1);
    root->right = ArrayToTree(array, index * 2 + 2);
    return root;
}

void MidOrder(TreeNode* tree, vector<int>& result) {
    if(tree != nullptr) {
        result.push_back(tree->val);
        MidOrder(tree->left, result);
        MidOrder(tree->right, result);
    }

}

int main() {

    vector<string> nums = {"1", "2", "null", "3", "4", "null", "null", "5"};
    TreeNode* root = ArrayToTree(nums, 0);
    vector<int> result;
    MidOrder(root, result);

    for(int num:result) {
        cout << num << " ";
    }

    return 0;
}