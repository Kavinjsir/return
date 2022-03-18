// https://leetcode.com/problems/move-zeroes
func moveZeroes(nums []int) {
	pos, size, zeroCount := 0, len(nums), 0
	for pos < size-zeroCount {
		if nums[pos] != 0 {
			pos++
			continue
		}
		zeroCount++

		for j := pos + 1; j < size; j++ {
			nums[j-1] = nums[j]
		}

		nums[size-zeroCount] = 0
	}
}
