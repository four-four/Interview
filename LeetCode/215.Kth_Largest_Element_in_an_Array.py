"""
215. Kth Largest Element in an Array    Medium

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
"""

class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        length = len(nums)
        self.buildHeap(nums, length)
        print(nums)

        for i in range(k - 1):
            nums[length - 1 - i], nums[0] = nums[0], nums[length - 1 - i]
            self.heapify(nums, 0, length - 1 -i)
            print(nums)
        return nums[0]

    def heapify(self, nums, index, length):
        if index >= length:
            return

        left = 2 * index + 1
        right = 2 * index + 2
        maxIndex = index

        if left < length and nums[left] > nums[maxIndex]:
            maxIndex = left

        if right < length and nums[right] > nums[maxIndex]:
            maxIndex = right

        if maxIndex != index:
            nums[maxIndex], nums[index] = nums[index], nums[maxIndex]
            self.heapify(nums, maxIndex, length)
    
    def buildHeap(self, nums, length):
        lastNode = length - 1
        start = int((lastNode - 1) / 2)

        while start >= 0:
            self.heapify(nums, start, length)
            start -= 1


if __name__ == "__main__":
    nums = [3,2,3,1,2,4,5,5,6]
    k = 2
    so = Solution()
    result = so.findKthLargest(nums, k)
    print(result)