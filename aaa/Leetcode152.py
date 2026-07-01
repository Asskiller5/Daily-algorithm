#https://leetcode.cn/problems/maximum-product-subarray/
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_product = min_product = ans = nums[0]
        for num in nums[1:]:
            if num < 0:
                max_product, min_product = min_product, max_product
            max_product = max(num, max_product * num)
            min_product = min(num, min_product * num)
            ans = max(ans, max_product)
        return ans
