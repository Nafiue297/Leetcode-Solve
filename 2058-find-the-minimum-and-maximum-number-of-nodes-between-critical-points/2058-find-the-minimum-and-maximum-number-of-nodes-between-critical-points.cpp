/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       ListNode* prev=head;
       ListNode* curr=head->next;
       int i=1;
       int prevcrit=0;
       int finalcrit=0;
       int mindist=INT_MAX;
     while(curr->next!=NULL)
     {
        if(curr->val > prev->val and curr->val > curr->next->val or curr->val < prev->val and curr->val < curr->next->val)
        {
            if(prevcrit==0)
            {
                prevcrit=i;
                finalcrit=i;
            }
            else
            {
              mindist=min(mindist,i-prevcrit);
              prevcrit=i;
            }

        }
        i++;
        prev=curr;
        curr=curr->next;
     }
   return mindist == INT_MAX
    ? vector<int>{-1, -1}
    : vector<int>{mindist, prevcrit-finalcrit};
    }
};