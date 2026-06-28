#https://leetcode.cn/problems/permutations/
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def dfs(path, used):
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i in range(len(nums)):
                if used[i]:
                    continue
                used[i] = True
                path.append(nums[i])
                dfs(path, used)
                path.pop()
                used[i] = False

        dfs([], [False] * len(nums))
        return ans
