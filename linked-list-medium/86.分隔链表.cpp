/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (59.11%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    47.3K
 * Total Submissions: 79.9K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
 * 
 */

// @lc code=start
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *before_head = new ListNode();
        ListNode *before = before_head;
        ListNode *after_head = new ListNode();
        ListNode *after = after_head;
        while(head)
        {
            if(head->val<x)
            {
                before->next = head;
                before = before -> next;
            }
            else
            {
                after -> next = head;
                after = after -> next;
            }
            head = head -> next;
        }
        after -> next = NULL;
        before -> next = after_head -> next;
        return before_head->next;
    }
};
// @lc code=end

