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

bool isPalindrome(ListNode* head) {
    if(head == nullptr) return true;

    int half = 0;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast){
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
        half++;
    }

    ListNode* prev = NULL;
    while(slow){
        ListNode* ahead = slow->next;
        slow->next = prev;
        prev = slow;
        slow = ahead;
    }

    ListNode* rev = prev;
    while(half-- && rev){
        if(head->val != rev->val) return false;
        head  = head->next;
        rev = rev->next;
    }

    return true;
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
    ListNode* head;

    std::cin >> n;
	for(int i = 0; i < n; ++i){
		std::cin >> val;
		head = append(head, val);
	}

	std::cout << std::boolalpha << isPalindrome(head) << "\n";

	return 0;
}


