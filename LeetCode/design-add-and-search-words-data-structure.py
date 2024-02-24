# https://leetcode.com/problems/design-add-and-search-words-data-structure/
class Trie:
    class Node:
        def __init__(self) -> None:
            self.childs = {}
            self.is_end_of_word = False

        def add_child(self, c: chr) -> None:
            if c in self.childs:
                return
            self.childs[c] = Trie.Node()

    def __init__(self) -> None:
        self.root = self.Node()

    def add(self, word: str) -> None:
        it = self.root
        for c in word:
            it.add_child(c)
            it = it.childs[c]
        it.is_end_of_word = True

    def contains(self, word: str) -> bool:
        it = self.root
        return self.__find(self.root, word, 0)

    def __find(self, node: Node, word: str, i: int) -> bool:
        if node is None:
            return False

        if i == len(word):
            return node.is_end_of_word

        if word[i] != '.':
            return self.__find(node.childs.get(word[i]), word, i + 1)

        for child in node.childs.values():
            if self.__find(child, word, i + 1):
                return True

        return False



class WordDictionary:
    def __init__(self):
        self.trie = Trie()

    def addWord(self, word: str) -> None:
        self.trie.add(word)

    def search(self, word: str) -> bool:
        return self.trie.contains(word)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
