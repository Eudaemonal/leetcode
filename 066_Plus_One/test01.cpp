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

std::vector<int> plusOne(std::vector<int>& digits){
    int n = digits.size();
    bool carry = true;
    for(int i = n-1; i >= 0; --i){
        if(++digits[i] % 10 != 0){
            carry = false;
            break;
        }else {
            digits[i] = 0;
        }
    }
    if(carry) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << plusOne(v);
    return 0;
}
