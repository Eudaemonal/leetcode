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

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> res(n, std::vector<int>(n));
    if(n == 0) return res;
    int c1 = 0, c2 = n-1;
    int r1 = 0, r2 = n-1;
    int count = 1;
    while(c1 <= c2 && r1 <= r2){
        for(int c = c1; c <= c2; ++c) {
            res[r1][c] = count++;
        }
        for(int r = r1 + 1; r <= r2; ++r) {
            res[r][c2] = count++;
        }
        if(c1 < c2 && r1 < r2){
            for(int c = c2-1; c >= c1+1; --c){
                res[r2][c] = count++;
            }
            for(int r = r2; r >= r1+1; --r){
                res[r][c1] = count++;
            }
        }
        c1++;
        c2--;
        r1++;
        r2--;
    }
    return res;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
	
	std::cout << generateMatrix(n);
	return 0;
}
