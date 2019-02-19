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

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int index = m+n-1;

    while(i >= 0 && j >=0 && index >= 0){
        if(nums1[i] >= nums2[j]){
            nums1[index--] = nums1[i--];
        }else{
            nums1[index--] = nums2[j--];
        }
    }

    while(j >=0 && index >=0){
        nums1[index--] = nums2[j--];
    }
}

int main(int argc, char *argv[]){
    int n, m, num;
    std::cin >> m >> num;
    std::vector<int> v1(num);
    for(int i = 0; i < num; ++i){
        std::cin >> v1[i];
    }

    std::cin >> n >> num;
    std::vector<int> v2(num);
    for(int i = 0; i < num; ++i){
        std::cin >> v2[i];
    }
    
    merge(v1, m, v2, n);

    std::cout << v1;
    return 0;
}
