#include <iostream>
#include <vector>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}

template <template <typename, typename...> class ContainerType, 
          typename ValueType, typename... Args>
std::ostream& operator<<(std::ostream& os, const ContainerType<ValueType, Args...>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* node, std::vector<int>& v){
    if(node == NULL) return;
    inorder(node->left, v);
    v.push_back(node->val);
    inorder(node->right, v);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> v;
    inorder(root, v);
    return v;
}

int main(int argc, char *argv[]){
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    std::cout << inorderTraversal(root);
}
