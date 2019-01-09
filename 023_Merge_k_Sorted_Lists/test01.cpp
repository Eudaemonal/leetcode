#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

std::ostream& operator<<(std::ostream& os, ListNode* curr){
    while(curr){
        os << curr->val;
        os << " ";
        curr = curr->next;
    }
    os << "\n";
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    for(const auto& c : v){
        os << c;
        os << " ";
    }
    os << "\n";
    return os;
}

struct compare{
    bool operator()(const ListNode* l, const ListNode* r){
        return l->val > r->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, compare> q;
    for(auto list : lists){
        if(list){
            q.push(list);
        }
    }
    if(q.empty()){
        return nullptr;
    }

    ListNode* result = q.top();
    q.pop();
    if(result->next){
        q.push(result->next);
    }

    ListNode* tail = result;
    while(!q.empty()){
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next){
            q.push(tail->next);
        }
    }
    return result;
}

ListNode* append(ListNode* head, int val){
    ListNode* node = new ListNode(val);
    if(head == nullptr){
        head = node;
    }
    else{
        ListNode* curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = node;
    }
    return head;
}

int main(int argc, char *argv[]){
    int n, m, val;
    std::vector<ListNode*> lists;

    std::cin >> n;
    for(int i = 0; i < n; ++i){
        ListNode* list = nullptr;
        std::cin >> m;
        for(int j = 0; j < m; ++j){
            std::cin >> val;
            list = append(list, val);
        }
        lists.push_back(list);
    }

    std::cout << mergeKLists(lists);
}
