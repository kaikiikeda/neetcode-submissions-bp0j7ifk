class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSub, maxSub = 0, nums[0]

        for n in nums:
            if curSub < 0:
                curSub = 0
            curSub += n
            maxSub = max(maxSub, curSub)
        return maxSub