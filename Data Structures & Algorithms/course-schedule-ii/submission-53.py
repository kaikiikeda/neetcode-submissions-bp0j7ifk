class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        premap = {i:[] for i in range(numCourses)}

        for crs, pre in prerequisites:
            premap[crs].append(pre)
        
        visited = set()
        cycle = set()
        res = []
        def dfs(crs):
            if crs in visited:
                return False
            if crs in cycle:
                return True
            visited.add(crs)
            for nei in premap[crs]:
                if not dfs(nei):
                    return False
            visited.remove(crs)
            cycle.add(crs)
            res.append(crs)
            return True
        
        for c in range(numCourses):
            if not dfs(c):
                return []
        return res
        