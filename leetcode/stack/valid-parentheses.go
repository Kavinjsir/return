func isValid(s string) bool {
	if s == "" {
		return true
	}
	pairs := map[rune]rune{
		'}': '{',
		']': '[',
		')': '(',
	}

	stk := make([]rune, 0, 1)
	var l int
	for _, ch := range s {
		switch ch {
		case 40, 123, 91:
			stk = append(stk, ch)
		default:
			l = len(stk)
			if l == 0 || stk[l-1] != pairs[ch] {
				return false
			} else {
				stk = stk[:l-1]
			}
		}
	}
	return len(stk) == 0
}

