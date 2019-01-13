#include <iostream>

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

ListNode* reverseKGroup(ListNode* head, int k){
    if(head == nullptr || k == 1){
        return head;
    }
    int len = 0;
    ListNode dummy(INT_MIN);
    dummy.next = head;
    ListNode* curr = &dummy;
    ListNode* prev = &dummy;
    ListNode* next = nullptr;

    while(curr->next){
        len++;
        curr = curr->next;
    }
    while(len >= k){
        curr = prev->next;
        next = curr->next;
        for(int i = 0; i < k-1; ++i){
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        len -= k;
    }
    return dummy.next;
}

int main(int argc, char *argv[]){
    int k, n, val;
    std::cin >> k;
    std::cin >> n;
    ListNode* head = nullptr;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        head = append(head, val);
    }
    std::cout << reverseKGroup(head, k);
}
