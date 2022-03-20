// https://leetcode.com/problems/count-collisions-on-a-road/
func countCollisions(d string) int {
	count, start, carToR, size := 0, 0, 0, len(d)

	for start < size && d[start] == 'L' {
		start++
	}

	for start < size {
		if d[start] == 'R' {
			carToR += 1
		} else {
			if d[start] == 'L' {
				carToR += 1
			}
			count += carToR
			carToR = 0
		}
		start++
	}
	return count
}
