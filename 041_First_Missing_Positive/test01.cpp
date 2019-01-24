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

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; ++i){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for(int i = 0; i < n; ++i){
        if(nums[i] != i + 1){
            return i + 1;
        }
    }
    return n + 1;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << firstMissingPositive(v) << "\n";
    return 0;
}
