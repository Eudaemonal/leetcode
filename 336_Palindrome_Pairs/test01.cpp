#include <iostream>
#include <vector>
#include <string>
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


bool isPalindrome(std::string& s) {   
    int l=0, r=s.size()-1;
    while(l<r){if(s[l++]!=s[r--]) return false;}
    return true; 
}

std::vector<std::vector<int>> palindromePairs(std::vector<std::string>& words) {
    std::vector<std::vector<int>> res;
    int n = words.size();
    if(n<2) return res;

    std::unordered_map<std::string, int> m;
    for(int i=0; i<n ;++i){ auto s= words[i]; reverse(s.begin(),s.end());  m[s]=i;}
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<=words[i].size(); ++j){
            std::string st1 = words[i].substr(0,j);
            std::string st2 = words[i].substr(j);                
            
             if(m.count(st1) && isPalindrome(st2) && m[st1] != i) {
                 res.push_back({i, m[st1]});    
             }

             if(!st1.empty()&&m.count(st2) && isPalindrome(st1) && m[st2] != i) {
                 res.push_back({m[st2], i});
             }
        }            
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

    std::cout << palindromePairs(v);
    return 0;
}
