// https://leetcode.com/problems/move-zeroes
func moveZeroes(nums []int) {
	size := len(nums)

	newPos := 0
	for pos := 0; pos < size; pos++ {
		if nums[pos] != 0 {
			nums[newPos] = nums[pos]
			newPos++
		}
	}

	for newPos < size {
		nums[newPos] = 0
		newPos++
	}
}
