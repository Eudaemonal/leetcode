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

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
    for(auto row: v){
        for(auto it: row){
            os << it << " ";
        }
        os << "\n";
    }
    return os;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i< nums.size(); ++i){
        int target = -nums[i];
        int front = i + 1;
        int back = nums.size() - 1;
        while(front < back){
            int sum = nums[front] + nums[back];
            if(sum < target){
                front++;
            }
            else if(sum > target){
                back--;
            }
            else{
                std::vector<int> triplet(3);
                triplet[0] = nums[i];
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                res.push_back(triplet);

                while(front < back && nums[front] == triplet[1]) front++;
                while(front < back && nums[back] == triplet[2]) back--;
            }
        }
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
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

    std::cout << threeSum(v);
    return 0;
}
