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

std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> res;
    if(k > n) return res;
    std::vector<int> v(k);

    for(int i = 0; i < k; ++i){
        v[i] = i+1;
    }
    res.push_back(v);

    while(true){
        bool finish = true;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] != n-k+i+1){
                finish = false;
                break;
            }
        }
        if(finish){
            return res;
        }

        for(int i = v.size() - 1; i >=0; i--){
            if(v[i] != n-k+i+1){
                v[i]++;
                for(int j = i+1; j < v.size(); ++j){
                    v[j] = v[j-1] + 1;
                }
                res.push_back(v);
                break;
            }
        }
    }
    return res;
}

int main(int argc, char *argv[]){
	int n, k;
	std::cin >> n >> k;

	std::cout << combine(n, k);
	return 0;
}
