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

int removeDuplicates(std::vector<int>& nums){
    int n = nums.size();
    std::unordered_map<int, int> map;
    
    for(auto it = nums.begin(); it != nums.end();){
        if(map.find(*it) != map.end() && map[*it] == 2){
            it = nums.erase(it);
            continue;
        }
        map[*it]++;
        ++it;
    }
    return nums.size();
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << removeDuplicates(v) << "\n";
    std::cout << v;
    
    return 0;
}
