#include <iostream>
#include <vector>

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

std::vector<std::vector<int>> generate(int numRows){
    std::vector<std::vector<int>> res;
    for(int i = 0; i < numRows; ++i){
        std::vector<int> row;
        if(i > 0){
            row.push_back(1);
        }
        for(int j = 1; j < i; ++j){
            row.push_back(res[i-1][j-1] + res[i-1][j]);
        }
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n;
	
	std::cout << generate(n);
	return 0;
}
