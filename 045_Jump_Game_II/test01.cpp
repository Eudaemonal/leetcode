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

int jump(std::vector<int>& nums) {
    int n = nums.size();
    int step = 0;
    int start = 0, end = 0;

    while(end < n-1){
        step++;
        int maxend = end + 1;
        for(int i = start; i <= end; ++i){
            if(i + nums[i] >= n-1){
                return step;
            }
            maxend = std::max(maxend, i + nums[i]);
        }
        start = end + 1;
        end = maxend;
    }
    return step;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << jump(v) << "\n";
    return 0;
}
