#include <iostream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode* root, long min, long max){
    if(root == NULL) return true;

    return (root->val < max && root->val > min) && 
           (isValidBST(root->left, min, root->val)) &&
           (isValidBST(root->right, root->val, max));
}

bool isValidBST(TreeNode* root) {
    return isValidBST(root, LONG_MIN, LONG_MAX);
}

int main(int argc, char *argv[]){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    std::cout << std::boolalpha << isValidBST(root) << "\n";

}
