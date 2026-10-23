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
    bool hasCycle(ListNode *head) {
        ListNode* result = head;
        unordered_set<ListNode*> visited;
        
        if (head == nullptr) return false;

        while (head->next != nullptr) {
            visited.insert(head);
            ListNode* next = head->next;
            if (visited.contains(next)) return true;    
            head = head->next;
        }
        return false;
    }
};