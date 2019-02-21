#include <iostream>
#include <queue>
#include <vector>

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

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder){
    if(preorder.empty() || inorder.empty()) return NULL;

    int val = preorder.front();
    preorder.erase(preorder.begin());
    auto pos = find(inorder.begin(), inorder.end(), val);
    TreeNode *root = new TreeNode(val);

    std::vector<int> inorder_l(inorder.begin(), pos);
    std::vector<int> inorder_r(pos+1, inorder.end());

    root->left = buildTree(preorder, inorder_l);
    root->right = buildTree(preorder, inorder_r);

    return root;
}


int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v1(n);
    std::vector<int> v2(n);

    for(int i = 0; i < n; ++i){
        std::cin >> v1[i];
    }
    for(int i = 0; i < n; ++i){
        std::cin >> v2[i];
    }

    std::cout << buildTree(v1, v2);
    return 0;
}
