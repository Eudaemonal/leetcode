#include <iostream>
#include <vector>
#include <queue>

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

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::vector<int> res;
    if(n == 0) return res;

    std::priority_queue<std::pair<int, int>> pq;
    for(int i = 0; i < std::min(k, n); i++){
        pq.push(std::make_pair(nums[i], i));
    }
    if(!pq.empty()){
        res.push_back(pq.top().first);
    }

    for(int i = k; i < n; i++){
        pq.push(std::make_pair(nums[i], i));
        while(pq.top().second <= i - k){
            pq.pop();
        }
        res.push_back(pq.top().first);
    }
    return res;
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
    }

    std::cout << maxSlidingWindow(v, k);
    return 0;
}
