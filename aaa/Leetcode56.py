#https://leetcode.cn/problems/merge-intervals/
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda item: item[0])
        ans = []
        for left, right in intervals:
            if not ans or ans[-1][1] < left:
                ans.append([left, right])
            else:
                ans[-1][1] = max(ans[-1][1], right)
        return ans
