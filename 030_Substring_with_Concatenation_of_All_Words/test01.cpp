#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> v){
    for(auto it : v){
        os << it << " ";
    }
    os << "\n";
    return os;
}

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    if(s.length() == 0 || words.size() == 0) return {};
    std::unordered_map<std::string, int> counts;
    for(std::string word: words){
        counts[word]++;
    }
    int n = s.length();
    int num = words.size();
    int len = words[0].length();
    std::vector<int> index;

    for(int i = 0; i < n - num*len + 1; ++i){
        std::unordered_map<std::string, int> seen;
        int j = 0;
        for(j=0; j < num; ++j){
            std::string word = s.substr(i + j*len, len);
            if(counts.find(word) != counts.end()){
                seen[word]++;
                if(seen[word] > counts[word]){
                    break;
                }
            }
            else{
                break;
            }
        }
        if(j==num){
            index.push_back(i);
        }
    }
    return index;
}

int main(int argc, char *argv[]){
    std::string s, val;
    int n;
    std::vector<std::string> words;

    std::cin >> s;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        words.push_back(val);
    }

    std::cout << findSubstring(s, words);
}
