func maxProfit(prices []int) int {
	l, max, low, i := len(prices)-1, 0, prices[0], 0

	for i < l {
		for i < l && prices[i+1] <= prices[i] {
			i++
		}

		if prices[i] < low {
			low = prices[i]
		}

		for i < l && prices[i+1] >= prices[i] {
			i++
		}

		if prices[i]-low > max {
			max = prices[i] - low
		}
	}
	return max
}
