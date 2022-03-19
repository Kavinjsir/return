// https://leetcode.com/problems/remove-element/

func removeElement(nums []int, val int) int {
	r := 0

	for _, v := range nums {
		if v != val {
			nums[r] = v
			r++
		}
	}

	return r
}

/*
Another strategy: Use pivot to partition array. (Similar as quick sort)
Not as good as above one: 4ms, 2.1MB

func removeElement(nums []int, val int) int {
  sc, i := 0, 0
  l := len(nums)
  for i < l - sc {
    if nums[i] == val {
      sc++
      nums[i], nums[l - sc] = nums[l - sc], nums[i]
    } else {
      i++
    }
  }
  return l - sc
}
*/
