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

void sortColors(std::vector<int>& nums){
    int r = 0;
    int w = 0;
    int b = nums.size()-1;
    while(w <= b){ // unknown region is not empty
        if(nums[w] == 1)    // white
            w++;
        else if(nums[w] == 0){  // red
            std::swap(nums[w], nums[r]);
            r++;
            w++;  // not very obvious
        }
        else {  // blue
            std::swap(nums[w], nums[b]);
            b--;
        }
    }
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    sortColors(v);

    std::cout << v;
    return 0;
}
