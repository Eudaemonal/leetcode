#include <iostream>
#include <vector>
#include <set>
#include <map>

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

std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings) {
    std::vector<std::pair<int, int>> res;

    std::multimap<int, int> coords;
    for(const std::vector<int>& building: buildings){
        coords.emplace(building[0], building[2]);
        coords.emplace(building[1], -building[2]);
    }
    
    std::multiset<int> heights = {0};
    std::map<int, int> corners;
    for(const std::pair<int, int>& p: coords){
        if(p.second > 0){
            heights.insert(p.second);
        }
        else {
            heights.erase(heights.find(-p.second));
        }

        int cur_y = *heights.rbegin();
        corners[p.first] = cur_y;
    }


    std::function<bool(std::pair<int, int> l, std::pair<int, int> r)> equal = [](std::pair<int, int> l, std::pair<int, int> r){ return l.second == r.second;  };
		
    std::unique_copy(corners.begin(), corners.end(), std::back_insert_iterator<std::vector<std::pair<int, int>>>(res), equal);
    return res;
}

int main(int argc, char *argv[]){
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n, std::vector<int>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			std::cin >> v[i][j];
		}
	}
	
	std::cout << getSkyline(v);
	return 0;
}
