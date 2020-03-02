/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (28.45%)
 * Total Accepted:    230.3K
 * Total Submissions: 806.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    int getListLength(ListNode* head) {
        int i = 0;
        while(head) {
            head = head->next;
            i++;
        }
        return i;
    }

    ListNode* cutAndMergeList(ListNode* head, int cutPoint) {
        
        if (!head) {
            return NULL;
        }
        ListNode* curr = head, *pre = NULL;

        while (cutPoint > 0) {
            pre = curr;
            curr = curr->next;
            cutPoint--;
        }
        pre->next = NULL;
        
        ListNode* newHead = curr;

        while(curr->next) {
            curr = curr->next;
        }

        curr->next = head;
        return newHead;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        int N = getListLength(head);
        if (0 == N) {
            return head;
        }

        int cutPoint = N - k % N;
        if (cutPoint == N) {
            return head;
        }

        ListNode* newHead = cutAndMergeList(head, cutPoint);
        return newHead;
    }
};

