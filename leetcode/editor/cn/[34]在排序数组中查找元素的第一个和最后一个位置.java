//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 你的算法时间复杂度必须是 O(log n) 级别。 
//
// 如果数组中不存在目标值，返回 [-1, -1]。 
//
// 示例 1: 
//
// 输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4] 
//
// 示例 2: 
//
// 输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1] 
// Related Topics 数组 二分查找 
// 👍 603 👎 0


import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len=nums.length;
        int left=0;
        int right=len-1;
        int ans[]=new int[2];
        ans[0]=-1;
        ans[1]=-1;
        if(nums.length==0){
            return ans;
        }
        while(left<right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                right=mid;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid;
            }
        }
        ans[0]=left;
        left=0;
        right=len;
        while(left<right){
            int mid=(left+right)/2;
            System.out.println("left:"+left);
            System.out.println("right"+right);
            System.out.println("mid"+mid);
            if(nums[mid]==target){
                left=mid+1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                right=mid;
            }
        }
        ans[1]=left-1;
        for(int i=0;i<2;i++){
            if(ans[i]!=-1&&nums[ans[i]]!=target){
                ans[i]=-1;
            }
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
