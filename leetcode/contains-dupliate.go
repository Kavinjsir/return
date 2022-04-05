func containsDuplicate(nums []int) bool {
	r := map[int]bool{}
	for _, v := range nums {
		_, ok := r[v]
		if ok {
			return true
		}
		r[v] = true
	}

	return false
}

