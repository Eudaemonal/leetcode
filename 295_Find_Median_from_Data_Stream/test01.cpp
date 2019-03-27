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

class MedianFinder {
    std::priority_queue<int> lo;
    std::priority_queue<int, std::vector<int>, std::greater<int>> hi;

public:
    void addNum(int num) {
        lo.push(num);

        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};


int main(int argc, char *argv[]){
    int n, num;
    std::cin >> n;

    MedianFinder obj;


    for(int i = 0; i < n; ++i){
        std::cin >> num;
        obj.addNum(num);
        std::cout << obj.findMedian() << "\n";

    } 
    
    return 0;
}
