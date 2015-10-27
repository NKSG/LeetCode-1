/*LeetCode [259] 3Sum Smaller 
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2. Return 2. 
Because there are two triplets which sums are less than 2: [-2, 0, 1] [-2, 0, 3]
Could you solve it in O(n^2) runtime?
和2Sum，3Sum，3Sum close很如出一辙的题目。考的基本还是双指针对排序数组的。
基于已经完成排序的数组，关键点是一旦找到 i, j 满足nums[i] + nums[j] + nums[k] < target, 
因为数组已排序，则（i, j-1, k),(i, j – 2, k)…(i, i+1, k)均是满足条件的解，这些解总共是 j – i个，而无需一个一个check它们。
*/
// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (nums[i] + nums[j] + nums[k] >= target) {
                    --j;
                } else {
                    count += j - i;
                    ++i;
                }
            }
        }

        return count;
    }
};
