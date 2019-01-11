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

ListNode* swapPairs(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* curr = head->next;
    ListNode* prev = head;
    ListNode* temp;

    prev->next = curr->next;
    curr->next = prev;
    head = curr;
    while(prev->next){
        temp = prev->next; 
        curr = temp->next;
        if(curr == nullptr){
            break;
        }
        temp->next = curr->next;
        curr->next = temp;
        prev->next = curr;
        prev = temp;
    }
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
    int n, val;
    std::cin >> n;
    ListNode* head = nullptr;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        head = append(head, val);
    }
    std::cout << swapPairs(head);
}
