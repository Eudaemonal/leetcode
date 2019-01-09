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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(INT_MIN);
    ListNode* curr = &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            curr->next = l1;
            l1 = l1->next;
        }
        else{
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if(l1 == nullptr && l2 != nullptr){
        curr->next = l2;
    }
    else if(l1 != nullptr && l2 == nullptr){
        curr->next = l1;
    }

    return dummy.next;
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
    ListNode* l1;
    ListNode* l2;

    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        l1 = append(l1, val);
    }

    std::cin >> m;
    for(int i = 0; i < m; ++i){
        std::cin >> val;
        l2 = append(l2, val);
    }

    std::cout << mergeTwoLists(l1, l2);
}
