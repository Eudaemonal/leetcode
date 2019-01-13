#include <iostream>
#include <vector>
#include <string>

int strStr(std::string haystack, std::string needle){
    int n = haystack.length();
    int m = needle.length();
    if(m == 0) return 0;

    std::vector<int> table(m);
    int i = 1, j = 0;
    while(i < m -1){
        if(needle[i] != needle[j]){
            if(j > 0){
                j = table[j - 1];
            }else{
                i++;
            }
        }
        else{
            table[i] = j + 1;
            i++;
            j++;
        }
    }

    i = 0;
    int match_pos = 0;
    while(i < n){
        if(haystack[i] == needle[match_pos]){
            if(match_pos == m - 1){
                return i - (m-1);
            }else{
                i++;
                match_pos++;
            }
        }
        else{
            if(match_pos == 0){
                i++;
            }else{
                match_pos = table[match_pos - 1];
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[]){
    std::string haystack;
    std::string needle;

    std::cin >> haystack;
    std::cin >> needle;

    std::cout << strStr(haystack, needle) << "\n";
}
