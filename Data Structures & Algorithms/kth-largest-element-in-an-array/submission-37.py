class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums = [-n for n in nums]
        heapq.heapify(nums)
        res = nums[0]

        while k > 0:
            val = -heapq.heappop(nums)
            res = val
            k -= 1
        return res
