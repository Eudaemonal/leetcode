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


std::vector<int> countBits(int num) {
    std::vector<int> res(num+1, 0);
    for(int i =1; i <= num; i++){
        res[i] = res[i/2] + (i & 0x1);
    }
    return res;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;

    std::cout << countBits(n);
    return 0;
}
