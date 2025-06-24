#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void PreOrder(TreeNode* root, vector<int>& result) {
    if(root != nullptr) {
        result.push_back(root->val);
        PreOrder(root->left, result);
        PreOrder(root->right, result);
    }
}

void VectorToBinaryTree(vector<int>& input, TreeNode* output, string ordertype) {
    if(ordertype == "preorder") {

    }
    else if(ordertype == "postorder") {

    }
    else if(ordertype == "middleorder") {

    }
    else {
        cout << "please input correct ordertype: preorder, middleorder, or postorder." << endl;
    }
}

// {1, 2, 3, 4, 5, 6, 7} 假设输入为完全二叉树结构, 
// 第i位置的元素，左子树在 2 * i + 1，右子树在 2 * i+ 2.
// verison 0.1, 是完全二叉树情况
void ArrayToTree(vector<int> & input, TreeNode*& output, int start) {
    if(start < input.size()) {
        output = new TreeNode(input[start]);
        ArrayToTree(input, output->left, start * 2 + 1);
        ArrayToTree(input, output->right, start * 2 + 2);
    }
    else {
        output = nullptr;
        return;
    }
}
// 这里是重载函数，函数返回值不同，参数个数不同，有返回值的函数，一定要正确return 返回值。
TreeNode* ArrayToTree(vector<int>& input, int index) {
    if(index >= input.size())
        return nullptr;
    
    TreeNode* tree_ptr = new TreeNode(input[index]);
    tree_ptr->left = ArrayToTree(input, index * 2 + 1);
    tree_ptr->right = ArrayToTree(input, index * 2 + 2);
    return tree_ptr;
}


int main() {

    vector<int> tree = {1, 2, 3, 4, 5};
    // TreeNode* tree_ptr;
    // ArrayToTree(tree, tree_ptr, 0);

    TreeNode* tree_ptr = ArrayToTree(tree, 0);
    vector<int> result;
    PreOrder(tree_ptr, result);

    for(int num:result) {
        cout << num << " ";
    }

    return 0;
}