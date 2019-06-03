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

int combinationSum4(std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<int> arr(target+1);
    arr[0] = 1;
    for(int i =1; i < target+1; i++){
        for(int j = 0; j < n; j++){
            if(i >= nums[j]) arr[i] += arr[i - nums[j]];
        }
    }
    return arr[target];
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << combinationSum4(v, k) << "\n";
    return 0;
}
