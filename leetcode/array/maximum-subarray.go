func maxSubArray(nums []int) int {
	l, s, m := len(nums), nums[0], nums[0]
	for i := 1; i < l; i++ {
		s += nums[i]
		if nums[i] > s {
			s = nums[i]
		}
		if s > m {
			m = s
		}
	}
	return m
}
