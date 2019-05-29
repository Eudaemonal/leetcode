#include <iostream>
#include <vector>
#include <utility>
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

std::vector<std::vector<int>> 
kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
    std::vector<std::vector<int>> v;
    if(nums1.empty() || nums2.empty()) return v;
    auto cmp = [&nums1, &nums2](const std::pair<int, int>& a, const std::pair<int, int>& b){
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);
    minHeap.emplace(0, 0);
    while(minHeap.size() && k--){
        auto t = minHeap.top();
        minHeap.pop();
        v.push_back(std::vector<int>{nums1[t.first], nums2[t.second]});
        if(t.first < nums1.size() - 1) minHeap.emplace(t.first+1, t.second);
        if(t.first == 0 && t.second < nums2.size() - 1) minHeap.emplace(t.first, t.second+1);
    }
    return v;
}

int main(int argc, char *argv[]){
    int k, n;
    std::cin >> k;
    std::cin >> n;
    std::vector<int> v1(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v1[i];
    }
    std::cin >> n;
    std::vector<int> v2(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v2[i];
    }

    std::cout << kSmallestPairs(v1, v2, k);
    return 0;
}
