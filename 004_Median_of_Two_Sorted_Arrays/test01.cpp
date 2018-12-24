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

    if(n > m){
        std::swap(nums1, nums2);
        std::swap(n, m);
    }

    int iMin = 0, iMax = n, halfLen = (n + m + 1)/2;
    while(iMin <= iMax){
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if(i < iMax && nums2[j-1] > nums1[i]){
            iMin = i + 1;
        }
        else if(i > iMin && nums1[i-1] > nums2[j]){
            iMax = i - 1;
        }
        else{
            int maxLeft = 0;

            if(i == 0) maxLeft = nums2[j - 1];
            else if(j == 0) maxLeft = nums1[i - 1];
            else maxLeft = std::max(nums1[i-1], nums2[j-1]);

            if( (n+m) % 2 ==1){ 
                return double(maxLeft); 
            }

            int minRight = 0;
            if(i == m) minRight = nums2[j];
            else if (j == n) minRight = nums1[i];
            else minRight = std::min(nums1[i], nums2[j]);

            return double(maxLeft + minRight) / 2;
        }
    }
    return 0;
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
