// https://leetcode.com/problems/sort-colors/
func sortColors(nums []int) {
	zeroPos, twoPos, idx := -1, len(nums), 0
	for idx < twoPos {
		if nums[idx] == 1 {
			idx++
		} else if nums[idx] == 0 {
			zeroPos++
			nums[zeroPos], nums[idx] = nums[idx], nums[zeroPos]
			idx++
		} else {
			twoPos--
			nums[twoPos], nums[idx] = nums[idx], nums[twoPos]
		}
	}
}
