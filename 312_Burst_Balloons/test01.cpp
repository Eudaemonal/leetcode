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

int maxCoins(std::vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size(), 0));
    for(int len = 1; len <= n; ++len){
        for(int left = 1; left <= n-len+1; ++left){
            int right = left + len - 1;
            for(int k = left; k <= right; ++k){
                dp[left][right] = std::max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
            }
        }
    }
    return dp[1][n];
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << maxCoins(v) << "\n";
    return 0;
}
