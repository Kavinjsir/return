// https://leetcode.com/problems/binary-search/
func search(nums []int, target int) int {
	leftPos, rightPos := 0, len(nums)-1
	for leftPos <= rightPos {
		midPos := (leftPos + rightPos) / 2

		switch mid := nums[midPos]; {
		case target == mid:
			return midPos
		case target < mid:
			rightPos = midPos - 1
		default:
			leftPos = midPos + 1
		}
	}
	return -1
}
