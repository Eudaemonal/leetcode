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

int numSquares(int n) {
    std::vector<int> dp(1);
    while(dp.size() <= n){
        int m = dp.size(), squares = INT_MAX;
        for(int i = 1; i*i <= m; i++){
            squares = std::min(squares, dp[m - i*i] + 1);
        }
        dp.push_back(squares);
    }
    return dp[n];
} 

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    
    std::cout << numSquares(n) << "\n";
    return 0;
}
