class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr) return head;
        if(left == right) return head;

        ListNode* t = head;
        ListNode* before = nullptr;

        int pos = 1;

        // Move t to the left position
        while(pos < left)
        {
            before = t;
            t = t->next;
            pos++;
        }

        ListNode* curr = t;
        ListNode* prev = nullptr;

        int time = right - left + 1;

        // Reverse left -> right
        while(time--)
        {
            ListNode* nex = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nex;
        }

        // Connect reversed part to remaining list
        t->next = curr;

        // If reversal didn't start from head
        if(before)
        {
            before->next = prev;
            return head;
        }

        // If left == 1
        return prev;
    }
};