#include <iostream>
#include <vector>
#include <string>

std::string getPermutation(int n, int k) {
    int ptable = n;
    int temp;
    std::vector<char> set(n, '1');
    for(int i = 1; i < n; ++i) {
        ptable *= i;
        set[i] = set[i-1] + 1;
    }
    std::string res;
    while(n > 0) {
        ptable /= n;
        temp = (k-1)/ptable;
        res += set[temp];
        set.erase(set.begin() + temp);
        k -= temp * ptable;
        n--;
    }
    return res;
}

int main(int argc, char *argv[]){
    int n, k;
    std::cin >> n >> k;

    std::cout << getPermutation(n, k);    
}
