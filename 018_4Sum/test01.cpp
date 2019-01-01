#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c){
    for(const auto& v : c){
        os << v << ' ';
    }
    os << '\n';
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(auto it: v[i])
			os << it << " ";
		os << "\n";
	}
	return os;
}

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target){
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i){
        for(int j = i + 1; j < nums.size(); ++j){
            int front = j + 1;
            int back = nums.size() - 1;
            while(front < back){
                int sum = nums[i] + nums[j] + nums[front] + nums[back];
                if(sum > target){
                    back--;
                }else if(sum < target){
                    front++;
                }else{
                    std::vector<int> elem = {nums[i], nums[j], nums[front], nums[back]};
                    res.push_back(elem);
                    while(front < back && nums[front] == elem[2]){ 
                        front++; 
                    }
                    while(front < back && nums[back] == elem[3]){
                        back--;
                    }
                }
                while(j < nums.size() - 1 && nums[j+1] == nums[j]){
                    j++;
                }
            }
            while(i < nums.size() - 1 && nums[i+1]==nums[i]){
                i++;
            }
        }
    }
    return res;
}




int main(int argc, char *argv[]){
    int n;
    int t;
    std::cin >> t;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << fourSum(v, t);
    return 0;
}
