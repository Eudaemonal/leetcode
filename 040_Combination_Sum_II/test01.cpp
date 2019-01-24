#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(auto it: v){
		for(auto elem : it){
			os << elem << " ";
		}
		os << "\n";
	}
	return os;
}

void combinationSum2(std::vector<std::vector<int>>& res, int order, int target, std::vector<int>& local, std::vector<int>& num) {
    if(target == 0){
        res.push_back(local);
        return;
    }
    else{
        for(int i = order; i < num.size(); ++i){
            if(num[i] > target) return;
            if(i && num[i] == num[i-1] && i > order) continue;
            local.push_back(num[i]);
            combinationSum2(res, i+1, target-num[i], local, num);
            local.pop_back();
        }
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
    std::vector<std::vector<int>> res;
    std::sort(candidates.begin(), candidates.end());
    combinationSum2(res, 0, target, std::vector<int>()={}, candidates);
    return res;
}

int main(int argc, char *argv[]){
    int n, t;
    std::cin >> t;
    std::cin >> n;
    
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }
	
	std::cout << combinationSum2(v, t);
	return 0;
}
