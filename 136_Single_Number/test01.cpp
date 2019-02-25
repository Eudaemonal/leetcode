#include <iostream>
#include <unordered_map>
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

int singleNumber(std::vector<int>& nums){
    int n = nums.size();
    int res;
    std::unordered_map<int, int> map;
    for(int i = 0; i < n; ++i){
        map[nums[i]]++;
    }
    for(auto it: map){
        if(it.second == 1){
            res = it.first;
        }
    }
    return res;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << singleNumber(v) << "\n";
    return 0;
}
