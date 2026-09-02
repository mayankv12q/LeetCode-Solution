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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr ;
            curr = next;
        }

        int maxTwin = 0;
        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2){
            maxTwin = max(maxTwin, (p1->val + p2->val));
            p1 = p1->next;
            p2 = p2->next;
        }

        return maxTwin ;
    }
};