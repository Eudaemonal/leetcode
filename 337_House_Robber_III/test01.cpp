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

void rob(TreeNode* root, int &child, int &childchild){
    if(!root) return;
    
    int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
    rob(root->left, l1, l2);
    rob(root->right, r1, r2);

    child = l2 + r2 + root->val;
    childchild = std::max(l1, l2) + std::max(r1, r2);
}

int rob(TreeNode* root) {
    int child = 0, childchild = 0;
    rob(root, child, childchild);
    return std::max(child, childchild);
}


int main(int argc, char *argv[]){

}


