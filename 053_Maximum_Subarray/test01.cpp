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

int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    int cmax = 0;
    int max = INT_MIN;

    for(int i = 0; i < n; ++i){
        cmax = std::max(nums[i], cmax + nums[i]);
        if(cmax > max){
            max = cmax;
        }
    }
    return max;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << maxSubArray(v) << "\n";
    return 0;
}
