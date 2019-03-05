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

int minSubArrayLen(int s, std::vector<int>& nums) {
    int n = nums.size();
    int start = 0, sum = 0, len = INT_MAX;
    for(int i = 0; i < n; ++i){
        sum += nums[i];
        while(sum >= s){
            len = std::min(len, i + 1 - start);
            sum -= nums[start++];
        }
    }
    return (len != INT_MAX) ? len : 0;
}


int main(int argc, char *argv[]){
    int s;
    int n;
    std::cin >> s >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << minSubArrayLen(s, v) << "\n";
    return 0;
}
