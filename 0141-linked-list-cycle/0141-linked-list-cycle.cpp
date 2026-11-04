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
        ListNode* temp = head;
        unordered_set<ListNode*> visited;
        while(temp) {
            if(visited.find(temp) != visited.end()) {
                return true;
            }
            visited.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};