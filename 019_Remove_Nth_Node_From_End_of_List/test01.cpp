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


ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* offset = head;
    ListNode* curr = head;
    ListNode* prev = new ListNode(-1);
    prev->next = curr;

    for(int i = 1; i < n; ++i){
        offset = offset->next;
    }

    while(offset->next != NULL){
        offset = offset->next;
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;

    if(curr == head){
        return head->next;
    }

    delete curr;
    return head;
}

int main(int argc, char *argv[]){
    int k;
    int n, elem;
    std::cin >> k;
    std::cin >> n;

    std::cin >> elem;
    ListNode* prev = new ListNode(elem);
    ListNode* head = prev;
    for(int i = 1; i < n; ++i){
        std::cin >> elem;
        ListNode* node = new ListNode(elem);
        prev->next = node;
        prev = node;
    }

    std::cout << removeNthFromEnd(head, k);
}
