# https://leetcode.com/problems/clone-graph/
from typing import Optional, Dict


# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:
    def clone(self, node: Node, new_graph: Node, cloned: Dict[int, Node]):
        new_graph.val = node.val
        cloned[new_graph.val] = new_graph
        for neighbor in node.neighbors:
            if neighbor.val in cloned:
                new_graph.neighbors.append(cloned[neighbor.val])
                continue

            neighbor_clone = Node()
            new_graph.neighbors.append(neighbor_clone)
            self.clone(neighbor, neighbor_clone, cloned)

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return None

        new_graph = Node()
        cloned: Dict[int, Node] = {}
        self.clone(node, new_graph, cloned)
        return new_graph
