# https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie:
    class Node:
        def __init__(self) -> None:
            self.childs = {}
            self.is_end_of_word = False

    def __init__(self):
        self.root = self.Node()

    def insert(self, word: str) -> None:
        it = self.root
        for c in word:
            if c not in it.childs:
                it.childs[c] = self.Node()
            it = it.childs[c]
        it.is_end_of_word = True

    def search(self, word: str) -> bool:
        it = self.root
        for c in word:
            if c not in it.childs:
                return False
            it = it.childs[c]
        return it.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        it = self.root
        for c in prefix:
            if c not in it.childs:
                return False
            it = it.childs[c]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
