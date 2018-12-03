#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T, typename U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
    os << "[" << p.first << ", " << p.second << "]";
    return os;
}

template <template <typename, typename...> class ContainerType, 
          typename ValueType, typename... Args>
std::ostream& operator<<(std::ostream& os, const ContainerType<ValueType, Args...>& c){
    for(const auto& v : c){
        os << v << " ";
    }
    os << "\n";
    return os;
}


std::vector<int> f(int target, std::vector<int> v){
	int n = v.size();
    int complement;
    std::vector<int> res;
    std::unordered_map<int, int> m;
	for(int i = 0; i < n; ++i){
		m[v[i]] = i;
	}
    for(int i = 0; i < n; ++i){
        complement = target - v[i];
        // Each number can be only used once
        if(m.count(complement) && m[complement]!=i){
            res.push_back(i);
            res.push_back(m[complement]);
           	break;
        }
    }
    return res;
}

int main(int argc, char *argv[]){
	int n;
    int target;
    std::cin >> target;
	std::cin >> n;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i){
		std::cin >> v[i];
	}
	
	std::cout << f(target, v);
	return 0;
}
