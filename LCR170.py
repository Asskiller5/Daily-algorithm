#https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
class Solution:
    def reversePairs(self, record: List[int]) -> int:
        def mergesort(l,r):
            if l>=r:
                return 0
            mid=(l+r)//2
            res=mergesort(l,mid)+mergesort(mid+1,r)
            i,j=l,mid+1
            tmp[l:r+1]=record[l:r+1]
            for k in range(l,r+1):
                if i==mid+1:
                    record[k]=tmp[j]
                    j+=1
                elif j==r+1 or tmp[i]<=tmp[j]:
                    record[k]=tmp[i]
                    i+=1
                else:
                    record[k]=tmp[j]
                    j+=1
                    res+=mid-i+1
            return res
        tmp=[0]*len(record)
        return mergesort(0,len(record)-1)
