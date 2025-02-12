class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        max_sum = -1
        sum_d_to_top_two_nums = {}

        for num in nums:
            sum_d = sum(map(int, str(num)))
            if sum_d not in sum_d_to_top_two_nums:
                sum_d_to_top_two_nums[sum_d] = [num, None]
            else:
                max1, max2 = sum_d_to_top_two_nums[sum_d]
                if num > max1:
                    max2 = max1
                    max1 = num
                elif max2 is None or num > max2:
                    max2 = num
                sum_d_to_top_two_nums[sum_d] = [max1, max2]

        for max1, max2 in sum_d_to_top_two_nums.values():
            if max2 is not None:
                total = max1 + max2
                max_sum = max(max_sum, total)

        return max_sum