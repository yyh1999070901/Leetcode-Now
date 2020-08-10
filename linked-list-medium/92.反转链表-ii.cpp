/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (50.97%)
 * Likes:    464
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 130.6K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *vHead = new ListNode;
        vHead -> next = head;
        ListNode *start = head;
        ListNode *end = head;
        ListNode *cur = vHead;
        ListNode *fakeHead;
        ListNode *fakeTail;
        int cnt = 0;
        while(cnt<=n){
            if(cnt == m-1){
                fakeHead = cur;
            }
            if(cnt == m){
                start = cur;
            }
            if(cnt == n){
                end = cur;
                fakeTail = cur->next;
            }
            cnt++;
            cur = cur -> next;
        }
        int num = n - m + 1;
        ListNode *temp = start;
        while(num--){
            ListNode *tempn = temp -> next;
            temp -> next = fakeTail;
            fakeTail = temp;
            temp = tempn;
        }
        fakeHead-> next = end;
        return vHead -> next;
    }
};
// @lc code=end

