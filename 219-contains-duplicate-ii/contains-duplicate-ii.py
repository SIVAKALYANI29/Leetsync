class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        window = set()
        
        for i, num in enumerate(nums):
            if num in window:
                return True
            
            window.add(num)
            
            if len(window) > k:
                window.remove(nums[i - k])
                
        return False
