class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        store = []
        res = []

        for i in range(len(points)):
            x, y = points[i]
            dist = x ** 2 + y ** 2
            store.append([dist, (x, y)])
        
        heapq.heapify(store)
        while len(res) < k:
            res.append(heapq.heappop(store)[1])
        return res