class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1Size = nums1.size();
    int n2Size = nums2.size();
    int total_len = n1Size + n2Size;
    
    vector<int> record;
    int m;
    if (total_len % 2 == 0) {
      m = total_len / 2;
    } else {
      m = (total_len - 1) / 2;
    }
    int l = m + 1;
    int p = 0;
    int q = 0;
    while (record.size() < l && (p < n1Size || q < n2Size)) {
      while (record.size() < l && p < n1Size && q < n2Size && nums1[p] <= nums2[q]) {
        record.push_back(nums1[p]);
        p++;
      }
      
      while (record.size() < l && q < n2Size && p < n1Size && nums2[q] < nums1[p]) {
        record.push_back(nums2[q]);
        q++;
      }
      
      while (record.size() < l && q >= n2Size && p < n1Size) {
        record.push_back(nums1[p]);
        p++;
      }
      
      while (record.size() < l && p >= n1Size && q < n2Size) {
        record.push_back(nums2[q]);
        q++;
      }
    }
    
    double result;
    if (total_len % 2 == 0) {
      result = (record[m] + record[m - 1]) / 2.0; 
    } else {
      result = record[m] / 1.0;
    }
    return result;
  }
};
