// https://leetcode.com/problems/minimum-size-subarray-sum
func minSubArrayLen(target int, nums []int) int {
	s := len(nums)
	j := s + 1
	arr := make([]int, s+1)

	for i := 1; i <= s; i++ {
		arr[i] = arr[i-1] + nums[i-1]
	}

	for l := 0; l < s; l++ {
		for r := l; r < s; r++ {
			if arr[r+1]-arr[l] >= target {
				if r-l+1 < j {
					j = r - l + 1
				}
			}
		}
	}

	if j > s {
		return 0
	}
	return j
}
