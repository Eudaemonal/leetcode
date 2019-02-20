#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* t1, TreeNode* t2) {
    if(t1 == NULL && t2 == NULL) return true;
    if(t1 == NULL || t2 == NULL) return false;
    if(t1->val != t2->val) return false;

    return isSymmetric(t1->left, t2->right) && isSymmetric(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return isSymmetric(root->left, root->right);
}



int main(int argc, char *argv[]){
    try{

        return EXIT_SUCCESS;
    }catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
