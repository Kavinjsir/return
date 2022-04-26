// https://github.com/golang/go/wiki/SliceTricks#reversing

func reverse(a []int) {
	l := len(a)
	for i := l/2 - 1; i >= 0; i-- {
		opp := l - 1 - i
		a[i], a[opp] = a[opp], a[i]
	}
}

func rotate(nums []int, k int) {
	k = k % len(nums)
	reverse(nums)
	reverse(nums[:k])
	reverse(nums[k:])
}

