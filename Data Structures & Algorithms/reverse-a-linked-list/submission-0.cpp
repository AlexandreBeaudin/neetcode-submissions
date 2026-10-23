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
    ListNode* reverse_helper(ListNode* ogList, ListNode* revList) {
        if (ogList == nullptr) {
            return revList;
        }
        ListNode* newNode = new ListNode;
        newNode->val = ogList->val;
        newNode->next = revList;

        return reverse_helper(ogList->next, newNode);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse_helper(head, nullptr);
    }
};
