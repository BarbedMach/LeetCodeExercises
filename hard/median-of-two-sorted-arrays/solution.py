from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # not the best solution, but the easiest one
        # time complexity: O(nlogn)
        # space complexity: O(n)
        nums = sorted(nums1 + nums2)
        n = len(nums)
        if n % 2 == 0:
            return (nums[n//2] + nums[n//2-1]) / 2
        else:
            return nums[n//2]
        # O(log(m + n)) binary search solution is too complicated for me
        # https://www.youtube.com/watch?v=q6IEA26hvXc

