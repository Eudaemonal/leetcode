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

std::vector<int> searchRange(std::vector<int>& nums, int target){
    int start = 0;
    int end = nums.size();
    int mid, left, right;
    while(start < end){
        mid = (start + end) / 2;
        if(nums[mid] >= target){
            end = mid;
        }else{
            start = mid + 1;
        }
    }

    left = start;
    start = 0;
    end = nums.size();
    while(start < end) {
        mid = (start + end) / 2;
        if(nums[mid] > target){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    right = start;
    return (left == right) ? std::vector<int>{-1, -1} : std::vector<int> {left, right - 1};
}

int main(int argc, char *argv[]){
    int t;
    int n;
    std::cin >> t;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << searchRange(v, t);
    return 0;
}
