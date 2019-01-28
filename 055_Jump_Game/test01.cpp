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

bool canJump(std::vector<int>& nums) {
    int n = nums.size();
    int max = 0;
    for(int i = 0; i < n; ++i){
        if(i <= max){
            max = std::max(max, i + nums[i]);
        }
        if(max >= n-1){
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << std::boolalpha << canJump(v) << "\n";
    return 0;
}
