// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
func twoSum(numbers []int, target int) []int {
	left, right := 0, len(numbers)-1

	for numbers[left]+numbers[right] != target {
		if numbers[left]+numbers[right] < target {
			left++
		} else {
			right--
		}
	}

	return []int{left + 1, right + 1}
}
