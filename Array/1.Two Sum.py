class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict={}
        for idx,value in enumerate(nums):
            key = target - value
            if key in dict:
                return [idx, dict[key]]
            dict[value] = idx
                
        return []