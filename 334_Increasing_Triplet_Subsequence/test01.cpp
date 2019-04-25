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

bool increasingTriplet(std::vector<int>& nums){
    int c1 = INT_MAX, c2 = INT_MAX;
    for(int x: nums){
        if(x <= c1){
            c1 = x;
        }else if(x <= c2){
            c2 = x;
        }else{
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

    std::cout << std::boolalpha << increasingTriplet(v) << "\n";
    return 0;
}
