#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int t, vector<int>& nums) {
  int l = 0, r = 0, s = 0;
  int vol = nums.size();
  int count = vol + 1;
  
  cout<<s<<" "<<r<<" "<<l<<"\n";
  while (l < vol) {
    if ( r < vol && s < t) {
      s += nums[r];
      r++;
    } else {
      s -= nums[l];
      l++;
    }
    cout<<s<<" "<<r<<" "<<l<<"\n";
    
    if (s >= t && r - l < count) {
      count = r - l;
    }
  }
  return count > vol ? 0 : count;
}

int main() {
  vector<int> n = { 2,3,1,2,4,3 };
  cout<<minSubArrayLen(7, n)<<"\n";
}
