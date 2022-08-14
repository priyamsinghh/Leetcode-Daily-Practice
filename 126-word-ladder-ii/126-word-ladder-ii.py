from collections import deque, defaultdict

class Solution:

    def __init__(self):
        self.distance = {}
        self.neighbors = {}


    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        path = []
        if not self.find_ladder_length(beginWord, endWord, wordList):
            return path

        self.dfs(path, endWord, [], beginWord)
        return path


    def dfs(self, result, end, curr_path, curr_word):
        if curr_word == end:
            result.append(curr_path[:] + [curr_word])
            return

        for next_word in self.neighbors[curr_word]:
            if next_word in self.distance and self.distance[next_word] < self.distance[curr_word]:
                curr_path.append(curr_word)
                self.dfs(result, end, curr_path, next_word)
                curr_path.pop()


    def find_ladder_length(self, beginWord, endWord, wordList):
        if not beginWord or len(beginWord) == 0 or \
            not endWord or len(endWord) == 0 or \
            not wordList or len(wordList) == 0 or \
            len(beginWord) != len(endWord):
            return False


        wordList = set(wordList)
        wordList.add(beginWord)
        word_queue = deque([endWord])
        seen = set([endWord])
        steps = 1

        while word_queue:
            size = len(word_queue)
            for _ in range(size):
                curr_word = word_queue.popleft()
                self.distance[curr_word] = steps
                next_words = self._gen_new_words(curr_word, wordList)
                self.neighbors[curr_word] = next_words
                if curr_word == beginWord:
                    return True

                for next_word in next_words:
                    if next_word not in seen:
                        word_queue.append(next_word)
                        seen.add(next_word)

            steps += 1

        return False


    def _gen_new_words(self, curr_word, wordList):
        new_words = []
        for i in range(len(curr_word)):
            for code in 'abcdefghijklmnopqrstuvwxyz':
                if curr_word[i] == code:
                    continue
                tmp_word = curr_word[:i] + code + curr_word[i + 1:]
                if tmp_word in wordList:
                    new_words.append(tmp_word)
                    # wordList.remove(tmp_word)

        return new_words