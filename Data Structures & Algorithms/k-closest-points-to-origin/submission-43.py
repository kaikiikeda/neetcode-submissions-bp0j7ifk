class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        res = []
        store = []

        for x, y in points:
            dist = x ** 2 + y ** 2
            store.append([dist, [x, y]])
        
        heapq.heapify(store)
        while len(res) < k:
            val = heapq.heappop(store)[1]
            res.append(val)
        return res