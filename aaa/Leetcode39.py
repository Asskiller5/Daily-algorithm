#https://leetcode.cn/problems/combination-sum/
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        ans = []

        def dfs(start, path, total):
            if total == target:
                ans.append(path[:])
                return
            for i in range(start, len(candidates)):
                num = candidates[i]
                if total + num > target:
                    break
                path.append(num)
                dfs(i, path, total + num)
                path.pop()

        dfs(0, [], 0)
        return ans
