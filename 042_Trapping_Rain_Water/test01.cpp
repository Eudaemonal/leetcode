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

int trap(std::vector<int>& height) {
    int n = height.size();
    if(n <= 2) return 0;
    int lmax = height[0];
    int rmax = height[n-1];
    int i = 1, j = n-2;

    int res = 0;
    while(i <= j){
        if(lmax <= rmax) {
            res += (height[i] >= lmax) ? 0: lmax - height[i];
            lmax = std::max(lmax, height[i]);
            ++i;
        }else{
            res += (height[j] >= rmax) ? 0: rmax - height[j];
            rmax = std::max(rmax, height[j]);
            --j;
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

    std::cout << trap(v) << "\n";
    return 0;
}
