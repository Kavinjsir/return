func rotate(nums []int, k int) {
	k = k % len(nums)
	sort.SliceStable(nums, func(i, j int) bool {
		return true
	})

	sort.SliceStable(nums[:k], func(i, j int) bool {
		return true
	})

	sort.SliceStable(nums[k:], func(i, j int) bool {
		return true
	})
}
