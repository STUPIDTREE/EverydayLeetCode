#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(nullptr), right(nullptr) {} 
};

void BackIntraval(TreeNode* root, vector<int> & result) {
    if(root != nullptr) {
        BackIntraval(root->left, result);
        BackIntraval(root->right, result);
        result.push_back(root->val);
    }
}

int main() {
    vector<int> result;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    BackIntraval(root, result);
    for(auto num:result){
        cout << num << " ";
    }

}