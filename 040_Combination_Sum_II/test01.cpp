#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
    
}


int main(int argc, char *argv[]){
    int n, t;
    std::cin >> t;
    std::cin >> n;
    
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }
	
	std::cout << combinationSum2(v, t) << "\n";
	return 0;
}
