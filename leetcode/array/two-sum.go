func twoSum(nums []int, target int) []int {
	s := map[int]int{}
	for i, v := range nums {
		d, ok := s[target-v]
		if ok {
			return []int{i, d}
		}
		s[v] = i
	}
	return make([]int, 2)
}
