class Solution:
    def maxNumber(self, nums1: list[int], nums2: list[int], k: int) -> list[int]:
        m, n = len(nums1), len(nums2)
        
        def maxSubsequence(nums, length):
            stack = []
            drop = len(nums) - length
            for num in nums:
                while drop > 0 and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:length]
        
        def merge(sub1, sub2):
            res = []
            i, j = 0, 0
            while i < len(sub1) or j < len(sub2):
                if sub1[i:] > sub2[j:]:
                    res.append(sub1[i])
                    i += 1
                else:
                    res.append(sub2[j])
                    j += 1
            return res
        
        max_res = []
        start = max(0, k - n)
        end = min(k, m)
        
        for i in range(start, end + 1):
            sub1 = maxSubsequence(nums1, i)
            sub2 = maxSubsequence(nums2, k - i)
            combined = merge(sub1, sub2)
            if combined > max_res:
                max_res = combined
                
        return max_res
