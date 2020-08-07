/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (59.34%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    118.7K
 * Total Submissions: 199.9K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pre(TreeNode *root, vector<int>&v)
    {
        if(root == nullptr)
        {
            //cout<<"true"<<endl;
            v.push_back(-1);
            return;
        }

        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>v1;
        vector<int>v2;
        pre(p,v1);
        pre(q,v2);
        bool flag = true;
        cout<<v1.size()<<endl;
        if(v1.size()!=v2.size())
        {
            return false;
        }
        for(int i=0;i<v1.size();i++)
        {
            cout<<v1[i]<<' '<<endl;
            cout<<v2[i]<<' '<<endl;
            if(v1[i]!=v2[i])
            {
                
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

