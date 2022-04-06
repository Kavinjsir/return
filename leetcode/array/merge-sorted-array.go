func merge(nums1 []int, m int, nums2 []int, n int) {
	p1, p2, i := m+n-1, m-1, 0

	if n == 0 {
		return
	}

	if m == 0 {
		copy(nums1, nums2)
		return
	}

	for p2 >= 0 {
		nums1[p1] = nums1[p2]
		p1--
		p2--
	}

	p1 = n
	p2 = 0

	for p1 < m+n && p2 < n {
		if nums1[p1] < nums2[p2] {
			nums1[i] = nums1[p1]
			p1++
		} else {
			nums1[i] = nums2[p2]
			p2++
		}
		i++
	}

	if p2 >= n {
		for p1 < m+n {
			nums1[i] = nums1[p1]
			i++
			p1++
		}
		return
	}

	if p1 >= m+n {
		for p2 < n {
			nums1[i] = nums2[p2]
			i++
			p2++
		}
		return
	}
}
