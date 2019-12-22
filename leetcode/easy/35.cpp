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

//class Solution {
//public:
    //int searchInsert(vector<int>& nums, int target) {
      //auto p = equal_range(nums.begin(), nums.end(), target);
      //int lb = p.first - nums.begin();
      //int ub = p.second - nums.begin();
      //if (lb == ub) return lb;
      //else return lb;
    //}
//};
//
class Solution {
 public: 
  int searchInsert(vector<int>& nums, int target){
    int lb = this-> lower_bound(nums, target);
    return lb;
  }

 private:
  int lower_bound(vector<int>& nums, int target){
    int lb = 0, rb = nums.size();
    int mid;

    while(rb > lb){ // note: 等號不成立！！
      mid = (rb + lb ) / 2;
      if (nums[mid] >= target) rb = mid; // 注意等號
      else lb = mid + 1;
      //else if (nums[mid] < target) lb = mid + 1; // need +1 (since / 為無條件捨去)
      //else return mid;
    }
    return lb; // not found
  }
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {1,3,5,6};
  cout << sol.searchInsert(nums, 5)  << endl;
  cout << sol.searchInsert(nums, 2) << endl;
  cout << sol.searchInsert(nums, 7) << endl;
  cout << sol.searchInsert(nums, 0) << endl;

  vector<int> ans = {2,1,4,0};

  cout  << endl << "Reference answer " << ans << endl; 
}
