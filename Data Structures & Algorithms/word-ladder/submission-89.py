class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        wordSet.add(beginWord)
        indegree = defaultdict(list)

        for w in wordSet:
            for i in range(len(w)):
                pattern = w[:i] + "*" + w[i+1:]
                indegree[pattern].append(w)
        
        q = deque([beginWord])
        visited = set([beginWord])
        res = 1
        while q:
            for i in range(len(q)):
                w = q.popleft()
                if w == endWord:
                    return res
                for j in range(len(w)):
                    pattern = w[:j] + "*" + w[j+1:]
                    for nei in indegree[pattern]:
                        if nei not in visited:
                            q.append(nei)
                            visited.add(nei)
            res += 1
        return 0
