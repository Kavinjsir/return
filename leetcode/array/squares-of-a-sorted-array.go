func sortedSquares(nums []int) []int {
	l := len(nums)
	res := make([]int, l)

	if nums[0] >= 0 {
		for i, v := range nums {
			res[i] = v * v
		}
		return res
	}

	if nums[l-1] < 0 {
		for i, v := range nums {
			res[l-1-i] = v * v
		}
		return res
	}

	i := 0
	for i < l {
		if nums[i] >= 0 {
			break
		}
		i++
	}

	pos := i
	neg := make([]int, pos)
	i--
	for i >= 0 {
		neg[pos-1-i] = nums[i] * nums[i]
		i--
	}

	i = 0

	nl, k := pos, 0

	var tmp int
	for i < nl && pos < l {
		tmp = nums[pos] * nums[pos]

		if neg[i] < tmp {
			res[k] = neg[i]
			i++
		} else {
			res[k] = tmp
			pos++
		}

		k++
	}

	for i < nl {
		res[k] = neg[i]
		i++
		k++
	}

	for pos < l {
		res[k] = nums[pos] * nums[pos]
		pos++
		k++
	}

	return res
}
