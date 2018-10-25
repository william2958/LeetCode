/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *returnNode = new ListNode(0);
        ListNode *rootNode = returnNode;
        
        ListNode *nextNode1 = l1;
        ListNode *nextNode2 = l2;
        
        while(nextNode1 != NULL || nextNode2 != NULL) {
            if (nextNode1 != 0) {
                
                returnNode->val += nextNode1->val;
                
                // Set the nextNode1 to be the next node in the list
                nextNode1 = nextNode1->next;
            } 
            if (nextNode2 != 0) {
                
                returnNode->val += nextNode2->val;
                
                nextNode2 = nextNode2->next;
            }
            if (returnNode->val >= 10) {
                // This is if the value of the two numbers add up to more than 10, in which case we 
                // need to carry over a 1
                returnNode->next = new ListNode(1);
                returnNode->val -= 10;
            } else {
                // If the next nodes contain something, set up a new ListNode
                if (nextNode1 != NULL || nextNode2 != NULL) {
                    returnNode->next = new ListNode(0);
                }
            }
            returnNode = returnNode->next;
        }
        
        return rootNode;
    }
};