func searchInsert(nums []int, target int) int {
	l, r := 0, len(nums)-1
	var m int
	for l <= r {
		m = (l + r) / 2
		if nums[m] == target {
			return m
		}
		if nums[m] < target {
			l = m + 1
		} else {
			r = m - 1
		}
	}
	if nums[m] < target {
		return m + 1
	}
	return m
}
