func sortedSquares(nums []int) []int {
	l, r := 0, len(nums)-1
	pos := r
	res := make([]int, r+1)

	for l <= r {
		if nums[l]+nums[r] <= 0 {
			res[pos] = nums[l] * nums[l]
			l++
		} else {
			res[pos] = nums[r] * nums[r]
			r--
		}
		pos--
	}
	return res
}
