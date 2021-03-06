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
    int k;
    int n, val;
    std::cin >> k;
    std::cin >> n;

    ListNode* head;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        head = append(head, val);
    }
    std::cout << removeNthFromEnd(head, k);
}
