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

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    std::vector<int> dp(n+2);

    for(int i = 2; i < n+2; ++i){
        dp[i] = std::max(dp[i-2] + nums[i-2], dp[i-1]);
    }
    std::cout << dp;
    return dp[n+1];
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << rob(v) << "\n";
    return 0;
}
