class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        count = Counter(tasks)
        count = [-c for c in count.values()]
        heapq.heapify(count)
        q = deque()
        time = 0

        while q or count:
            time += 1
            if count:
                curr = heapq.heappop(count)
                curr += 1
                if curr != 0:
                    q.append([time + n, curr])
            if q and q[0][0] == time:
                heapq.heappush(count, q.popleft()[1])
        return time