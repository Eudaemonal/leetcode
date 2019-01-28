#include <iostream>
#include <vector>

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

ListNode* rotateRight(ListNode* head, int k) {
    if(!head) return head;
    int n = 0;
    ListNode* curr = head;
    while(curr->next) {
        curr = curr->next;
        n++;
    }
    k = k % (n+1);

    ListNode* last = curr;
    curr = head;
    int i = 0;
    while(i < n - k){
        curr = curr->next;
        i++;
    }
    last->next = head;
    head = curr->next;
    curr->next = nullptr;

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
    int k, n, val;
    std::cin >> k;
    std::cin >> n;

    ListNode* head;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        head = append(head, val);
    }

    std::cout << rotateRight(head, k);
    return 0;
}
