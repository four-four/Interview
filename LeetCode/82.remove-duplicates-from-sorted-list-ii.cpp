/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.79%)
 * Total Accepted:    215.9K
 * Total Submissions: 618.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* delDup(ListNode* head, int val, bool *find) {
        if (!head) {
            return NULL;
        }
        bool removeSelf = false;

        head->next = delDup(head->next, head->val, find);
        if (*find) {
            removeSelf = true;
        }
        if (head->val == val) {
            *find = true;
            removeSelf = true;
        } else {
            *find = false;
        }
        if (removeSelf) {
            head = head->next;
        }
        return head;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        bool find = false;

        return delDup(head, head->next->val, &find);
    }
};

