// https://leetcode.com/problems/longest-substring-without-repeating-characters/
func lengthOfLongestSubstring(s string) int {
	chars := []rune(s)

	positionRecord := make([]int, 256)
	for i := range positionRecord {
		positionRecord[i] = -1
	}

	l, r, res, size := 0, -1, 0, len(chars)

	for r+1 < size {
		r++
		pos := positionRecord[chars[r]]
		if pos != -1 {
			if pos+1 > l {
				l = pos + 1
			}
		}
		if r-l+1 > res {
			res = r - l + 1
		}
		positionRecord[chars[r]] = r
	}
	return res
}
