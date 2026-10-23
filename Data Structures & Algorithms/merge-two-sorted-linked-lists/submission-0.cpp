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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newNode = new ListNode;

        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }

        if (list2 == nullptr) { // put the rest of list1 at the end
            newNode->val = list1->val;
            newNode->next = mergeTwoLists(list1->next, nullptr);
            return newNode;
        }
        if (list1 == nullptr) { // put the rest of list2 at the end
            newNode->val = list2->val;
            newNode->next = mergeTwoLists(nullptr, list2->next);
            return newNode;
        }

        if (list1->val < list2->val) {
            newNode->val = list1->val;
            newNode->next = mergeTwoLists(list1->next, list2);
            return newNode;
        }
        newNode->val = list2->val;
        newNode->next = mergeTwoLists(list1, list2->next);
        return newNode;
    }
};
