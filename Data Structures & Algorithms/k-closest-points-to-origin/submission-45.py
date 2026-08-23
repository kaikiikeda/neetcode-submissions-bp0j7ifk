class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        store = []
        res = []

        for x, y in points:
            dist = x ** 2 + y ** 2
            store.append([dist, (x, y)])
        
        heapq.heapify(store)
        while len(res) < k:
            val = heapq.heappop(store)
            res.append(val[1])
        return res