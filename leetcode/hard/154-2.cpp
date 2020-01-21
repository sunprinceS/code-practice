#include<bits/stdc++.h>
using namespace std;

template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
return s<<"("<<p.first<<","<<p.second<<")";
}

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
s<<"[ ";
for (auto it : c) s << it << " ";
s<<"]";
return s;
}

class Solution {
public:
    int findMin(vector<int>& nums) {
      return find_sub_min(nums, 0, nums.size()-1);
    }
    int find_sub_min(vector<int>& nums, int lb, int rb){
      if(lb >= rb) return nums[lb];

      int mid = (lb + rb) / 2;

      if((nums[lb] < nums[mid]) && (nums[mid + 1] > nums[rb])) return min(nums[lb], find_sub_min(nums, mid + 1, rb));
      if((nums[lb] > nums[mid]) && (nums[mid + 1] < nums[rb])) return min(nums[mid + 1], find_sub_min(nums, lb, mid));

      return min(find_sub_min(nums, lb, mid), find_sub_min(nums, mid+1, rb));
    }
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {3,4,5,1,2};
  cout << sol.findMin(nums) << endl;
  nums = {4,5,6,7,0,1,2};
  cout << sol.findMin(nums) << endl;

  nums = {3,1};
  cout << sol.findMin(nums) << endl;
  nums = {1,3};
  cout << sol.findMin(nums) << endl;
}
