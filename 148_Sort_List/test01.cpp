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

int length(ListNode *node){
    int n = 0;
    while (node != NULL){
        node = node->next;
        ++n;
    }
    return n;
}

ListNode *sortList(ListNode *head) {
    int block_size = 1, n = length(head), iter = 0, i = 0, n1 = 0, n2 = 0;
    ListNode dummy(0);
    ListNode *last = NULL, *curr = NULL, *list1 = NULL, *list2 = NULL, *tmp = NULL;
    dummy.next = head;
    while (block_size < n){
        iter = 0;
        last = &dummy;
        curr = dummy.next;
        while (iter <  n){
            n1 = std::min(n - iter, block_size);
            n2 = std::min(n - iter - n1, block_size);
            
            list1 = curr;
            if (n2 != 0){
                for (i = 0; i < n1 - 1; ++i) curr = curr->next;
                list2 = curr->next;
                curr->next = NULL;
                curr = list2;
                
                for (i = 0; i < n2 - 1; ++i) curr = curr->next;
                tmp = curr->next;
                curr->next = NULL;
                curr = tmp;
            }
            
            while (list1 || list2){
                if (list2 == NULL || (list1 != NULL && list1->val <= list2->val)){
                    last->next = list1;
                    last = last->next;
                    list1 = list1->next;
                } else {
                    last->next = list2;
                    last = last->next;
                    list2 = list2->next;
                }
            }
            last->next = NULL;
            iter += n1 + n2;
        }
        block_size <<= 1;
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
    int n, val;
    std::cin >> n;
    ListNode* head;
    for(int i = 0; i < n; ++i){
        std::cin >> val;
        head = append(head, val);
    }

    std::cout << sortList(head);
    return 0;
}
