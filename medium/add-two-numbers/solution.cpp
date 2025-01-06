struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        int carry = 0;

        ListNode* result = head;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1_val = (l1 != nullptr) ? l1->val : 0;
            int l2_val = (l2 != nullptr) ? l2->val : 0;

            int sum = l1_val + l2_val + carry;
            carry = sum / 10;

            head->val = sum % 10;

            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;

            if (l1 != nullptr || l2 != nullptr || carry != 0) {
                head->next = new ListNode();
                head = head->next;
            }
        }

        return result;
    }
};