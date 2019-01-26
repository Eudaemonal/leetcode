#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v){
	for(auto sv: v){
		for(auto it : sv){
			os << it << " ";
		}
		os << "\n";
	}
	return os;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> res;
    std::unordered_map<std::string, std::vector<std::string>> count;
    std::string s;
    for(auto str: strs){
        s = str;
        std::sort(s.begin(), s.end());
        count[s].push_back(str);
    }
    for(auto n : count){
        std::sort(n.second.begin(), n.second.end());
        res.push_back(n.second);
    }
    return res;
}

int main(int argc, char *argv[]){
	int n;
	std::cin >> n;
    std::vector<std::string> v(n);
	for(int i = 0; i < n; ++i){
        std::cin >> v[i];
	}
	
	std::cout << groupAnagrams(v);
	return 0;
}
