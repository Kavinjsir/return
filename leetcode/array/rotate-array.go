func rotate(nums []int, k int) {
	l := len(nums)
	steps := k % l
	tmp := make([]int, steps)
	for i := 0; i < steps; i++ {
		tmp[i] = nums[l-steps+i]
	}
	for j := l - steps - 1; j >= 0; j-- {
		nums[j+steps] = nums[j]
	}
	for j := 0; j < steps; j++ {
		nums[j] = tmp[j]
	}
}
