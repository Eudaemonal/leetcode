#include <iostream>
#include <vector>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

std::ostream& operator<<(std::ostream& os, const Interval& p) {
    os << "[" << p.start << ", " << p.end << "]";
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

std::vector<Interval> merge(std::vector<Interval>& intervals) {
    std::vector<Interval> res;
    int n = intervals.size();
    if(n == 0) return res;
    int start, end;
    std::sort(intervals.begin(), intervals.end(), [&](Interval& a, Interval& b){
        return a.start < b.start;
    });
    for(int i = 0; i < n; ++i){
        if(i == 0){
            start = intervals[i].start;
            end = intervals[i].end;
        }
        else if(intervals[i].start <= end){
            end = std::max(end, intervals[i].end);
        }
        else {
            res.push_back(Interval(start, end));
            start = intervals[i].start;
            end = intervals[i].end;
        }
    }
    res.push_back(Interval(start, end));

    return res;
}

int main(int argc, char *argv[]){
    int n;
    std::cin >> n;
    std::vector<Interval> v(n);
    for(int i = 0; i < n; ++i){
        std::cin >> v[i].start;
        std::cin >> v[i].end;
    }

    std::cout << merge(v);
    return 0;
}
