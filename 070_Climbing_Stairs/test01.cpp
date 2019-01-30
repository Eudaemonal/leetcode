#include <iostream>
#include <vector>

int climbStairs(int n){
    std::vector<int> dp(n);
    if(n == 0) return 0;
    for(int i = 0; i < n; ++i){
        if(i == 0){
            dp[i] = 1;
        }else if(i == 1){
            dp[i] = 2;
        }else {
            dp[i] = dp[i-1] + dp[i-2];
        }
    }
    return dp[n-1];
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;

    std::cout << climbStairs(n) << "\n";
}
