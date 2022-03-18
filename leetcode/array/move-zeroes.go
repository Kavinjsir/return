// https://leetcode.com/problems/move-zeroes
func moveZeroes(nums []int) {
	zeroCount := 0
	size := len(nums)

	for pos := 0; pos < size; pos++ {
		if nums[pos] == 0 {
			zeroCount++
			continue
		}

		if zeroCount == 0 {
			continue
		}

		nums[pos-zeroCount] = nums[pos]
	}

	for pos := size - zeroCount; pos < size; pos++ {
		nums[pos] = 0
	}
}
