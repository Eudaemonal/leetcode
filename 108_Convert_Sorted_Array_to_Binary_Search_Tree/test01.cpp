#include <iostream>
#include <queue>
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


TreeNode* sortedArrayToBST(std::vector<int>& nums, int start, int end){
    if(start >= end) return NULL;
    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid);
    root->right = sortedArrayToBST(nums, mid+1, end);
    return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return sortedArrayToBST(nums, 0, nums.size());
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << sortedArrayToBST(v);
    return 0;
}
