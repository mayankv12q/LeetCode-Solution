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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // A dummy node acts as the starting anchor. 
        // Its next pointer will hold the actual head of our result list.
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Loop runs as long as there's a node left in l1, a node left in l2, 
        // or a remaining carry over value to process.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the previous column's carry value
            
            // Add l1's value if it exists
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move forward
            }
            
            // Add l2's value if it exists
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move forward
            }
            
            // Calculate the new carry (e.g., 14 / 10 = 1)
            carry = sum / 10;
            
            // Create a new node with the single digit value (e.g., 14 % 10 = 4)
            current->next = new ListNode(sum % 10);
            
            // Advance our result list pointer
            current = current->next;
        }
        
        // Save the actual start pointer, delete the dummy allocation to clean up memory
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;
    }
};