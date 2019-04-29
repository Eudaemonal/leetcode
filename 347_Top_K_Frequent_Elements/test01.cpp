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

std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::unordered_map<int, int> freq;
    auto it = nums.begin();
    for(int n: nums) if(!freq[n]++) *it++ = n;
    nums.resize(freq.size());

    std::nth_element(nums.begin(), nums.begin() + (k-1), nums.end(),[&](int a, int b){
        return freq[a] > freq[b];        
    });
    nums.resize(k);
    return std::move(nums);
}



int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << topKFrequent(v, k);
    return 0;
}
