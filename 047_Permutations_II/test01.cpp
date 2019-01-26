#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &v){
	for(size_t i=0; i < v.size(); ++i){
			os << v[i] << " ";
	}
    os << "\n";
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(size_t i=0; i < v.size(); ++i){
		for(size_t j=0; j < v[0].size(); ++j){
			os << v[i][j] << " ";
		}
		os << "\n";
	}
	return os;
}

void permuteUnique(std::vector<int> nums, int begin, std::vector<std::vector<int>>& res) {
    int n = nums.size();
    if (begin == n-1) {
        res.push_back(nums);
        return;
    }
    for (int i = begin; i < n; ++i) {
        if (begin != i && nums[begin] == nums[i]) continue;
        std::swap(nums[begin], nums[i]);
        permuteUnique(nums, begin+1, res);
    }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums){
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;
    permuteUnique(nums, 0, res);
    return res;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
        std::cin >> v[i];
	}
	
	std::cout << permuteUnique(v);
	return 0;
}
