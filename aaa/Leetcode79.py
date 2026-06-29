#https://leetcode.cn/problems/word-search/
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def dfs(i, j, k):
            if board[i][j] != word[k]:
                return False
            if k == len(word) - 1:
                return True
            ch = board[i][j]
            board[i][j] = "#"
            for x, y in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                if 0 <= x < m and 0 <= y < n and board[x][y] != "#":
                    if dfs(x, y, k + 1):
                        board[i][j] = ch
                        return True
            board[i][j] = ch
            return False

        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
