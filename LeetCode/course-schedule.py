# https://leetcode.com/problems/course-schedule/description/
from typing import List
from queue import Queue


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        in_degree: List[int] = [0] * numCourses
        adjencency_list: List[List[int]] = [[] for _ in range(numCourses)]
        for prerequisite in prerequisites:
            in_degree[prerequisite[0]] += 1
            adjencency_list[prerequisite[1]].append(prerequisite[0])

        q = Queue()
        for i in range(numCourses):
            if in_degree[i] == 0:
                q.put(i)

        while not q.empty():
            u = q.get()
            for v in adjencency_list[u]:
                in_degree[v] -= 1
                if in_degree[v] == 0:
                    q.put(v)

        return in_degree.count(0) == numCourses
