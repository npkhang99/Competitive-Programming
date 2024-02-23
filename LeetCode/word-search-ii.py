# https://leetcode.com/problems/word-search-ii/description/
from typing import Dict, List


class Trie:
    class Node:
        def __init__(self) -> None:
            self.childs: Dict[chr, Trie.Node] = {}
            self.is_end_of_word = False

        def add_child(self, c: chr) -> None:
            if c in self.childs:
                return
            self.childs[c] = Trie.Node()

        def remove_child(self, c: chr) -> bool:
            if c not in self.childs:
                return True

            if len(self.childs[c].childs) > 0:
                return False

            del self.childs[c]
            return True

        def is_empty(self) -> bool:
            return len(self.childs) == 0

    def __init__(self) -> None:
        self.root = Trie.Node()

    def add(self, word: str) -> None:
        it = self.root
        for c in word:
            it.add_child(c)
            it = it.childs[c]
        it.is_end_of_word = True

    def remove(self, word: str) -> None:
        self.__remove(word, 0, self.root)

    def __remove(self, word: str, i: int, node: Node) -> bool:
        removable = True
        if i < len(word) - 1:
            removable = self.__remove(word, i + 1, node.childs[word[i]])

        if i == len(word) - 1:
            node.childs[word[i]].is_end_of_word = False

        if removable and not node.childs[word[i]].is_end_of_word and node.childs[word[i]].is_empty():
            del node.childs[word[i]]
            return True

        return False


class Solution:
    dx = [-1, 0, 0, 1]
    dy = [0, 1, -1, 0]

    trie: Trie = None

    def explore_words(
        self,
        board: List[List[str]],
        visited: List[List[bool]],
        i: int,
        j: int,
        n: int,
        m: int,
        node: Trie.Node,
        ans: List[str],
        s: str
    ) -> None:
        visited[i][j] = True
        if node.is_end_of_word:
            print(s, node.is_end_of_word, i, j)
            ans.append(s)
            self.trie.remove(s)

        for d in range(len(self.dx)):
            new_i = i + self.dx[d]
            new_j = j + self.dy[d]
            if 0 <= new_i < n and 0 <= new_j < m and not visited[new_i][new_j] and board[new_i][new_j] in node.childs:
                self.explore_words(board, visited, new_i, new_j, n, m,
                                   node.childs[board[new_i][new_j]], ans, s + board[new_i][new_j])

        visited[i][j] = False

    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        self.trie = Trie()

        for word in words:
            self.trie.add(word)

        n, m = len(board), len(board[0])
        visited = [[False] * m for _ in range(n)]
        ans: List[str] = []
        for i in range(n):
            for j in range(m):
                if board[i][j] in self.trie.root.childs:
                    self.explore_words(
                        board, visited, i, j, n, m, self.trie.root.childs[board[i][j]], ans, board[i][j])

        return ans
