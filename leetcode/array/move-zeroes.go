// https://leetcode.com/problems/move-zeroes
func moveZeroes(nums []int) {
	size := len(nums)
	for p, k := 0, 0; p < size; p++ {
		if nums[p] != 0 {
			if k != p {
				nums[k], nums[p] = nums[p], nums[k]
			}
			k++
		}
	}
}
