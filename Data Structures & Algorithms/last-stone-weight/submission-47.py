class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-s for s in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            v1 = -heapq.heappop(stones)
            v2 = -heapq.heappop(stones)
            val = abs(v1- v2)
            heapq.heappush(stones, -val)
        return -stones[0]