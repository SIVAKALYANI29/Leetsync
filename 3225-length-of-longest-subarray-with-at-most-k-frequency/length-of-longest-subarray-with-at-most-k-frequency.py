class Solution(object):
    def maxSubarrayLength(self, nums, k):
        frequency = {}
        left = 0
        max_len = 0
        
        for right in range(len(nums)):
            # Add current element frequency
            current = nums[right]
            frequency[current] = frequency.get(current, 0) + 1
            
            # Shrink window if the frequency exceeds k
            while frequency[current] > k:
                frequency[nums[left]] -= 1
                left += 1
                
            # Track maximum valid window length
            max_len = max(max_len, right - left + 1)
            
        return max_len
