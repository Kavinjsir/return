// https://leetcode.com/problems/sort-colors/
func sortColors(nums []int) {
	zero, one, two, idx := 0, 0, 0, 0
	for _, element := range nums {
		if element == 2 {
			two += 1
		} else if element == 1 {
			one += 1
		} else {
			zero += 1
		}
	}

	for zero > 0 {
		nums[idx] = 0
		zero--
		idx++
	}

	for one > 0 {
		nums[idx] = 1
		one--
		idx++
	}

	for two > 0 {
		nums[idx] = 2
		two--
		idx++
	}
}
