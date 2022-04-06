func sortedSquares(nums []int) []int {
	l, r := 0, len(nums)-1
	sl, sr, pos := 0, 0, r
	res := make([]int, r+1)

	for l <= r {
		sl = nums[l] * nums[l]
		sr = nums[r] * nums[r]
		if sl >= sr {
			res[pos] = sl
			l++
		} else {
			res[pos] = sr
			r--
		}
		pos--
	}
	return res
}
