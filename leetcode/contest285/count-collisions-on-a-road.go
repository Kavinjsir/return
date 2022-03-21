// https://leetcode.com/problems/count-collisions-on-a-road/
func countCollisions(d string) int {
	d = strings.TrimRight(d, "R")

	count, start, size := 0, 0, len(d)

	for start < size && d[start] == 'L' {
		start++
	}

	for start < size {
		if d[start] == 'R' {
			count += 1
		} else {
			if d[start] == 'L' {
				count += 1
			}
		}
		start++
	}
	return count
}
