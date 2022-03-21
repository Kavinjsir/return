// https://leetcode.com/problems/count-collisions-on-a-road/
int countCollisions(string d) {
  int s = d.size();
  int l = 0, r = s - 1, count = 0;
  while (l < s && d[l] == 'L') {
    l++;
  }
  while (r >= 0 && d[r] == 'R') {
    r--;
  }

  for (int i = l; i <= r; i++) {
    if (d[i] != 'S') {
      count++;
    }
  }
  return count;
}
