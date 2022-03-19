// https://leetcode.com/problems/minimum-size-subarray-sum
func minSubArrayLen(target int, nums []int) int {
	l, r := 0, -1
	sum := 0
	size := len(nums)
	res := size + 1
	for l < size {
		if r+1 < size && sum < target {
			r++
			sum += nums[r]
		} else {
			sum -= nums[l]
			l++
		}

		if sum >= target && r-l+1 < res {
			res = r - l + 1
		}
	}

	if res > size {
		return 0
	}
	return res
}
