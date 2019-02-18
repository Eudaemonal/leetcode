#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(auto vec: v){
        os << "[";
		for(auto it: vec){
			os << it << " ";
		}
        os << "]";
		os << "\n";
	}
	return os;
}

void subsets(int begin, std::vector<int>& nums, std::vector<int>& subset, std::vector<std::vector<int>>& res){
    for(int i = begin; i < nums.size(); ++i){
        subset.push_back(nums[i]);
        res.push_back(subset);
        subsets(i+1, nums, subset, res);
        subset.pop_back();
    }
}


std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> subset;
    res.push_back(subset);

    subsets(0, nums, subset, res);    

    return res;
}


int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
        std::cin >> v[i];
	}
	
	std::cout << subsets(v);
	return 0;
}
