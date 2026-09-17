class Solution:
    def wiggleSort(self, nums: list[int]) -> None:
        nums.sort()
        mid = (len(nums) - 1) // 2
        
        
        small = nums[:mid + 1]
        large = nums[mid + 1:]
        
        for i in range(len(nums)):
            if i % 2 == 0:
                nums[i] = small.pop()
            else:
                nums[i] = large.pop()
