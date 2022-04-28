func reverseString(s []byte) {
	i, j := 0, len(s)-1
	var t byte
	for i < j {
		t = s[i]
		s[i] = s[j]
		s[j] = t
		i++
		j--
	}
}
