#include <iostream>
#include <vector>


template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<std::vector<T>> v){
    for(auto it : v){
        for(auto elem : it){
            os << elem << " ";
        }
        os << "\n";
    }
    return os;
}

void combinationSum(std::vector<std::vector<int>>& res, std::vector<int>& c, std::vector<int> s, int target, int idx){
    if(target == 0) res.push_back(s);
    else if(idx >= c.size() || c[idx] > target) return;
    else{
        combinationSum(res, c, s, target, idx+1);
        s.push_back(c[idx]);
        combinationSum(res, c, s, target - c[idx], idx);
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
    std::vector<std::vector<int>> res;
    std::sort(candidates.begin(), candidates.end());
    combinationSum(res, candidates, std::vector<int>() = {}, target, 0);
    return res;
}

int main(int argc, char *argv[]){
    int t;
    int n;
    std::cin >> t;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << combinationSum(v, t);
    return 0;
}
