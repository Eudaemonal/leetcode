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


int threeSumClosest(std::vector<int>& nums, int target) {
    int closest = INT_MAX + target;
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); ++i){
        int front = i + 1;
        int back = nums.size() - 1;
        while(front < back){
            int sum = nums[i] + nums[front] + nums[back];
            if(abs(sum - target) < abs(closest - target)){
                closest = sum;
            }

            if(sum > target){
                back--;
            }
            else if(sum < target){
                front++;
            }else{
                return sum;
            }
        }
    }
    return closest;
}

int main(int argc, char *argv[]){
    int target;
    int n;
    std::cin >> target;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << threeSumClosest(v, target) << "\n";
    return 0;
}
