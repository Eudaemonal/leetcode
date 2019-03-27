#include <iostream>
#include <string>
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


class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string res = "";
        preorder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        std::vector<std::string> strs;
        std::string str;

        while(ss >> str) {
            strs.push_back(str);
        }
        int i = 0;
        return buildNode(strs, i);
    }


    void preorder(TreeNode* root, std::string& str){
        if(!root) {
            str += " #";
            return;
        }
        str += (" " + std::to_string(root->val));
        preorder(root->left, str);
        preorder(root->right, str);
    }

    TreeNode* buildNode(const std::vector<std::string>& strs, int& i){
        if(i >= strs.size() || strs[i] == "#") return nullptr;
        TreeNode* root = new TreeNode(std::atoi(strs[i].c_str()));
        root->left = buildNode(strs, ++i);
        root->right = buildNode(strs, ++i);
        return root;
    }
};




int main(int argc, char *argv[]){

}


