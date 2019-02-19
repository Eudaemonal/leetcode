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

ListNode* deleteDuplicates(ListNode* head){
    if(head==NULL) return head;
    ListNode* curr = head->next;
    ListNode* prev = head;

    while(curr){
        if(prev->val == curr->val){
            prev->next = curr->next;
        }else{
            prev = prev->next;
        }
        curr = curr->next;
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
    ListNode* l;

    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        l = append(l, val);
    }

    std::cout << deleteDuplicates(l);
    return 0;
}
