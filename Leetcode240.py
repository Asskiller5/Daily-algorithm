#https://leetcode.cn/problems/search-a-2d-matrix-ii/
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m,n=len(matrix),len(matrix[0])
        i,j=0,n-1 #从右上角开始
        while i<m and j>=0:
            if matrix[i][j]==target:
                return True
            elif matrix[i][j]<target:
                i+=1# 这一行剩余元素全部小于 target，排除
            else:
                j-=1# 这一列剩余元素全部大于 target，排除
        return False