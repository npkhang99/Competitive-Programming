# https://leetcode.com/problems/alien-dictionary/
from queue import Queue
from typing import List, Dict, Set


class Solution:
    def kahn(self, graph: Dict[str, Set[str]]) -> str:
        indegrees = {c: 0 for c in graph.keys()}
        for (c, neighbors) in graph.items():
            for neighbor in neighbors:
                indegrees[neighbor] += 1

        q = Queue()
        for (c, indegree) in indegrees.items():
            if indegree == 0:
                q.put(c)

        ans = []
        while not q.empty():
            u = q.get()
            ans.append(u)
            for v in graph[u]:
                indegrees[v] -= 1
                if indegrees[v] == 0:
                    q.put(v)

        # we can't form a topological order if the answer list's length
        # does not equal to the number of vertices in the graph
        # => return an empty string
        return ''.join(ans) if len(ans) == len(graph) else ""

    def foreignDictionary(self, words: List[str]) -> str:
        # initialize a graph base on the available characters in the words list
        graph: Dict[str, Set[str]] = { c: set() for c in set(''.join(words)) }

        max_word_length = max(map(len, words))
        relation_formed = [False] * len(words)
        for p in range(max_word_length):
            for i in range(1, len(words)):
                if relation_formed[i]:
                    continue

                # impossible if there is a case where the smaller word is longer than the bigger word
                if len(words[i]) < p and p <= len(words[i - 1]):
                    return ""

                if p < len(words[i - 1]) and p < len(words[i]) and words[i - 1][p] != words[i][p]:
                    graph[words[i - 1][p]].add(words[i][p])
                    relation_formed[i] = True

        return self.kahn(graph)
