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

int searchInsert(std::vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid;
    int exp;
    while(begin <= end){
        mid = (end - begin) / 2 + begin;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid - 1;
            exp = mid;
        }
        else{
            begin = mid + 1;
            exp = mid + 1;
        }
    }
    return exp;
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

    std::cout << searchInsert(v, t) << "\n";
    return 0;
}
