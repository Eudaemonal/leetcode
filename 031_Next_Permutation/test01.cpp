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

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size(), k, l;
    for(k = n-2; k>=0; k--){
        if(nums[k] < nums[k+1]){
            break;
        }
    }
    if(k < 0){
        std::reverse(nums.begin(), nums.end());
    }
    else{
        for(l = n-1; l > k; l--){
            if(nums[l] > nums[k]){
                break;
            }
        }
        std::swap(nums[k], nums[l]);
        std::reverse(nums.begin() + k + 1, nums.end());
    }
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    nextPermutation(v);

    std::cout << v;
    return 0;
}
