#include <iostream>
#include <vector>
#include <string>


bool equal(char a, char b){
    if(a=='.' || b=='.')
        return true;
    return a==b;
}


bool isMatch(std::string s, std::string p){
    int n = s.length();
    int m = p.length();

    std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(m+1));
    dp[0][0] = true;
    for(int i = 0 ; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(p[j-1]=='*'){
                dp[i][j] = dp[i][j-2]||(i > 0 && (s[i-1] == p[j-2] || p[j-2]=='.') && dp[i-1][j]);
            }
            else{
                dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1]=='.');
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char *argv[]){
    std::string s;
    std::string p;
    std::cin >> s;
    std::cin >> p;

    std::cout << std::boolalpha << isMatch(s, p) << "\n";
    return 0;
}
