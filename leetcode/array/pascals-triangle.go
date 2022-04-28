func generate(numRows int) [][]int {
	var res [][]int

	for i := 0; i < numRows; i++ {
		record := make([]int, i+1)
		for i := range record {
			record[i] = 1
		}

		for j := 1; j < i; j++ {
			record[j] = res[i-1][j] + res[i-1][j-1]
		}
		res = append(res, record)
	}
	return res
}
