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
    int size(ListNode* head) {
        if (head == nullptr) {
            return 0;
        }
        return 1 + size(head->next);
    }
    int getEndVal(ListNode* head, int size) {
        if (size == 1) {
            return head->val;
        }
        return getEndVal(head->next, size - 1);
    }
    bool isPalindrome_helper(ListNode* head, int size) {
        if (head == nullptr || size <= 0) {  // the || size <= 0 handles the even # lists
            return true;
        }
        if (size == 1) {
            return true;
        }
        return (head->val == getEndVal(head, size)) && isPalindrome_helper(head->next, size - 2);
        // We do `size - 2` because we want to cut off the first and last number from consideration.
    }
    bool isPalindrome(ListNode* head) {
        // the subproblem can be broken up like
        // 12321 -> 232 -> 3 -> nullptr
        // 123321 -> 2332 -> 33 -> nullptr
        int listSize = size(head);
        return isPalindrome_helper(head, listSize);
    }
};