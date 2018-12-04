#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


std::ostream& operator<<(std::ostream& os, ListNode *l){
	ListNode *curr = l;
	while(curr){
		os << curr->val << " ";
		curr = curr->next;
	}
	os << "\n";
	return os;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *res;
    ListNode *curr;

    int ans;
    int carry = 0;

    ans = l1->val + l2->val;
    carry = ans / 10;
    ans = ans % 10;
    res = new ListNode(ans);
    curr = res;
    l1 = l1->next;
    l2 = l2->next;
    while( l1!=NULL && l2!=NULL ){
        ans = l1->val + l2->val + carry;
        carry = ans / 10;
        ans = ans % 10;
        curr->next = new ListNode(ans);
        curr = curr->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL){
        ans = l1->val + carry;
        carry = ans / 10;
        ans = ans % 10;

        curr -> next = new ListNode(ans);
        curr = curr ->next;
        l1 = l1->next;
    }
    while(l2 != NULL){
        ans = l2->val + carry;
        carry = ans / 10;
        ans = ans % 10;

        curr -> next = new ListNode(ans);
        curr = curr ->next;
        l2 = l2->next;
    }
    if(carry != 0){
        curr -> next = new ListNode(carry);
    }

    return res;
}


int main(int argc, char *argv[]){
	ListNode *l1;
	ListNode *l2;
    ListNode *curr;

	int n1, n2, e;
	std::cin >> n1;
	for(int i = 0; i < n1; ++i){
		std::cin >> e;
        if(i==0){
            l1 = new ListNode(e);
            curr = l1;
        }else{
            curr->next = new ListNode(e);
            curr = curr->next;
        }
	}
	std::cin >> n2;
	for(int i = 0; i < n2; ++i){
		std::cin >> e;
        if(i==0){
            l2 = new ListNode(e);
            curr = l2;
        }else{
            curr->next = new ListNode(e);
            curr = curr->next;
        }
	}

	std::cout << l1;
    std::cout << l2;

    std::cout << addTwoNumbers(l1, l2);

	return 0;
}


