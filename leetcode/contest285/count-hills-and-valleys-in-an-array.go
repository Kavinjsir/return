// https://leetcode.com/problems/count-hills-and-valleys-in-an-array/submissions/
func countHillValley(nums []int) int {
	size := len(nums)
	if size <= 2 {
		return 0
	}

	arr := make([]int, len(nums))
	arr[0] = nums[0]

	dup := 0
	j := 0

	for i := 1; i < size; i++ {
		if nums[i] == arr[j] {
			dup++
		} else {
			j++
			arr[j] = nums[i]
		}
	}

	size -= dup
	if size <= 2 {
		return 0
	}

	nonDup := arr[:size]
	count := 0
	for i := 1; i < size-1; i++ {
		if nonDup[i] > nonDup[i-1] && nonDup[i] > nonDup[i+1] {
			count++
		} else if nonDup[i] < nonDup[i-1] && nonDup[i] < nonDup[i+1] {
			count++
		}
	}

	return count
}
