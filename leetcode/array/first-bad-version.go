/**
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
	l, r := 1, n
	m := (l + r) / 2
	for l <= r {
		if isBadVersion(m) == true {
			if m == 1 {
				return m
			}
			if isBadVersion(m-1) == false {
				return m
			}
			r = m - 1
		} else {
			if isBadVersion(m+1) == true {
				return m + 1
			}
			l = m + 1
		}
		m = (l + r) / 2
	}
	return m
}
