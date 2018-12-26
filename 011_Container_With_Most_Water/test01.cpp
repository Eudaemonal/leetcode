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

int maxArea(std::vector<int>& height) {
    int i = 0;
    int j = height.size() -1;
    int m;
    int max = 0;
    while(i < j){
        max = std::max(max, std::min(height[i], height[j])*(j-i));
        if(height[i] < height[j]){
            m = i;
            while(height[++i] <= height[m] && i < j);
        }else{
            m = j;
            while(height[--j] <= height[m] && i < j);
        }
    }
    return max;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << maxArea(v) << "\n";
    return 0;
}
