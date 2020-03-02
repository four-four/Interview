/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (39.18%)
 * Total Accepted:    189.4K
 * Total Submissions: 481.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* findPreX(ListNode* head, int x, bool *find) {
        ListNode *pre = NULL;
        while (head && head->val < x) {
            pre = head;
            head = head->next;
        }

        if (!head) {
            *find = false;
        } else {
            *find = true;
        }

        return pre;
    }

    ListNode* insertNodeX(ListNode* pos, ListNode* node) {
        if (!pos || !node) {
            return NULL;
        }
        node->next = pos->next;
        pos->next = node;
        return node;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) {
            return NULL;
        }
        bool find = false;
        ListNode *insertPos = findPreX(head, x, &find);
        if (!find) {
            return head;
        }

        ListNode *dummyHead = NULL;
        if (!insertPos) {
            dummyHead = new struct ListNode(x);
            dummyHead->next = head;
            insertPos = dummyHead;
        }

        ListNode *curr = insertPos->next;
        ListNode *pre = insertPos;
        while(curr) {
            if (curr->val < x) {
                ListNode *node = curr;
                pre->next = node->next;
                insertPos = insertNodeX(insertPos, node);
                curr = pre->next;
            } else {
                pre = curr;
                curr = curr->next;
            }
        }

        if (dummyHead) {
            return dummyHead->next;
        }
        return head;
    }
};

