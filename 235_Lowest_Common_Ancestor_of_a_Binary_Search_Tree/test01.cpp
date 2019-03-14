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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if((root->val > p->val) && (root->val > q->val)){
        return lowestCommonAncestor(root->left, p, q);
    }
    if((root->val < p->val) && (root->val < q->val)){
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}


int main(int argc, char *argv[]){

}


