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

int wiggleMaxLength(std::vector<int>& nums) {
    if(nums.empty()) return 0;
    int length = 0;

    int prev_sign = 0;
    for(int i = 0; i < nums.size() - 1; i++){
        int diff = nums[i+1] - nums[i];
        int sign = diff > 0 ? 1 : diff < 0 ? -1 : 0;
        if(sign != 0 && prev_sign != sign){
            length++;
            prev_sign = sign;
        }
    }
    return length + 1;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << wiggleMaxLength(v) << "\n";
    return 0;
}
