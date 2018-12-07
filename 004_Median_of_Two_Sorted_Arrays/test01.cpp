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

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
    int n = nums1.size();
    int m = nums2.size();

    std::vector<int> combined;
    int i =0, j=0;
    while(i < n && j < m){
        if(nums1[i] < nums2[j]){
            combined.push_back(nums1[i++]);
        }else{
            combined.push_back(nums2[j++]);
        }
    }
    while(i < n){
        combined.push_back(nums1[i++]);
    }
    while(j < m){
        combined.push_back(nums2[j++]);
    }

    int size = combined.size();
    if(size % 2){
        return double(combined[size/2]);
    }else{
        return double(combined[size/2-1] + combined[size/2])/2;
    }
}

int main(int argc, char *argv[]){
    int n, m;
    std::cin >> n;
    std::vector<int> v1(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v1[i];
    }
    std::cin >> m;
    std::vector<int> v2(m);
    for(int i = 0; i < m; ++i){
        std::cin >> v2[i];
    }

    std::cout << findMedianSortedArrays(v1, v2) << "\n";

    return 0;
}
