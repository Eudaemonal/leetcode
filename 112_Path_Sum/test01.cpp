#include <iostream>
#include <queue>

bool hasPathSum(TreeNode* root, int sum, int &s){
    if(root == NULL) return s == sum;
    if(root->left == NULL) return hasPathSum(root->right, sum, s+root->val);
    if(root->right == NULL) return hasPathSum(root->left, sum, s+root->val);

    return hasPathSum(root->right, sum, s+root->val) || hasPathSum(root->left, sum, s+root->val);
}

bool hasPathSum(TreeNode* root, int sum) {
    if(root == NULL) return false;
    hasPathSum(root, sum, 0);
}

int main(int argc, char *argv[]){
    
}
