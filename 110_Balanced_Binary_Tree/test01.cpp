#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::ostream& operator<<(std::ostream& os, TreeNode *root)  {  
    if (root == NULL) return os;
    std::queue<TreeNode*> q;

    q.push(root);
    while (q.empty() == false) {
        int count = q.size();
        while (count > 0) {
            TreeNode* node = q.front();
            os << node->val << " ";
            q.pop();
            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            count--;
        }
        os << "\n";
    }
    return os;
}


int depthOfTree(TreeNode* root, int depth){
    if(root == NULL) return 0;
    int ldepth = depthOfTree(root->left, depth) + 1;
    int rdepth = depthOfTree(root->right, depth) + 1;
    return std::max(ldepth, rdepth);
}

bool isBalanced(TreeNode* root){
    if(root == NULL) return true;
    if(abs(depthOfTree(root->left, 0) - depthOfTree(root->right, 0)) > 1){
        return false;
    }

    if(!isBalanced(root->left) || !isBalanced(root->right)){
        return false;
    }
    return true;
}

int main(int argc, char *argv[]){

}
