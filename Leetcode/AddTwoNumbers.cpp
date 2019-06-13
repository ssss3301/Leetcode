struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = nullptr;

	bool l1_finished = false;
	bool l2_finished = false;
	int carry = 0;
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	ListNode* p3 = nullptr;

	while (true) {
		int lhs = 0;
		int rhs = 0;

		if (l1_finished && l2_finished) {
			if (carry > 0) {
				ListNode* carryNode = new ListNode(carry);
				p3->next = carryNode;
			}
			break;
		}

		if (p1 != nullptr) {
			lhs = p1->val;
			p1 = p1->next;
			if (p1 == nullptr)
				l1_finished = true;
		}

		if (p2 != nullptr) {
			rhs = p2->val;
			p2 = p2->next;
			if (p2 == nullptr)
				l2_finished = true;
		}

		int sum = lhs + rhs + carry;
		carry = sum / 10;

		ListNode* node = new ListNode(sum % 10);
		if (head == nullptr) {
			head = node;
			p3 = head;
		}
		else {
			p3->next = node;
			p3 = node;
		}
	}
	
	return head;
}