class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        wordSet.add(beginWord)
        adj = defaultdict(list)
        for w in wordSet:
            for i in range(len(w)):
                pattern = w[:i] + "*" + w[i+1:]
                adj[pattern].append(w)
        
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
                    for nei in adj[pattern]:
                        if nei not in visited:
                            visited.add(nei)
                            q.append(nei)
            res += 1
        return 0