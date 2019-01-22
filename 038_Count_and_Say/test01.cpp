#include <iostream>
#include <vector>


std::string countAndSay(int n){
    if(n == 0) return "";
    if(n == 1) return "1";
    std::string res = "1";
    std::string s;

    for(int i = 1; i < n; ++i){
        int len = res.size();
        for(int j = 0; j < len; ++j){
            int count = 1;
            while(j + 1 < len && res[j] == res[j+1]){
                count++;
                j++;
            }
            s += std::to_string(count) + res[j];
        }
        res = s;
        s.clear();
    }
    return res;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;

    std::cout << countAndSay(n) << "\n";
    return 0;
}
