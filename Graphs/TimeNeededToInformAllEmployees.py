from email.policy import default
from typing import List
from collections import defaultdict

class CustomGraph:

    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited, informTime, timeNeeded):
        visited.add(v)

        time = timeNeeded + informTime[v]

        print("=> {}; cost = {}".format(v, time))
        maxTime = 0
        for neighbour in self.graph[v]:
            if neighbour not in visited:
                maxTime = max(maxTime, self.DFSUtil(neighbour,
                visited, informTime, time))

        time = max(time, maxTime)

        return time

    def DFS(self, v, informTime):
        visited = set()
        return self.DFSUtil(v, visited, informTime, 0)

class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        graph = CustomGraph()
        for i in range(len(manager)):
            if manager[i] != -1:
                graph.addEdge(manager[i], i)

        return graph.DFS(headID, informTime)

sol = Solution()
# sol.numOfMinutes(15, 0, [-1,0,0,1,1,2,2,3,3,4,4,5,5,6,6], [1,1,1,1,1,1,1,0,0,0,0,0,0,0,0])
# sol.numOfMinutes(6, 2, [2,2,-1,2,2,2], [0,0,1,0,0,0])
# sol.numOfMinutes(6, 2, [2,3,-1,2,2,3], [0,0,2,3,0,0])
# sol.numOfMinutes(1, 0, [-1], [0])