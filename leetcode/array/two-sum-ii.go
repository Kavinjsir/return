// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
func twoSum(numbers []int, target int) []int {
	left, right := 0, len(numbers)-1

	for left < right {
		sum := numbers[left] + numbers[right]
		if sum == target {
			break
		}

		if sum < target {
			left++
		} else {
			right--
		}
	}

	return []int{left + 1, right + 1}
}
