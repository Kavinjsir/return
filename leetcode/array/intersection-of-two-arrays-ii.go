func intersect(nums1 []int, nums2 []int) []int {
	var record [1001]int
	for _, v := range nums1 {
		record[v]++
	}

	var results []int
	for _, v := range nums2 {
		if record[v] != 0 {
			results = append(results, v)
			record[v]--
		}
	}

	return results
}
