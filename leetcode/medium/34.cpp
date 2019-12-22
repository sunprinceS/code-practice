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
    //vector<int> searchRange(vector<int>& nums, int target) {
      //auto p = equal_range(nums.begin(), nums.end(), target);
      //int lb = p.first - nums.begin();
      //int ub = p.second - nums.begin();

      //if (lb == ub) return {-1,-1};
      //else return {lb, ub-1};
    //}
//};
//
class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      int lb = this->lower_bound(nums, target);
      // 對於 upper_bound 不用從頭開始搜！
      int ub = this->lower_bound(nums, target + 1, lb);
      if (lb == ub) return {-1, -1};
      else return {lb, ub -1};
    }
private:
  int lower_bound(vector<int>& nums, int target, int start=0){
    int lb = start, rb = nums.size();
    int mid;

    while(rb > lb){
      mid = (rb + lb ) / 2;
      if (nums[mid] >= target) rb = mid;
      else lb = mid + 1;
    }
    return lb;
  }
};

int main(){
  Solution sol;
  vector<int> nums = {5,7,7,8,8,10};
  cout << sol.searchRange(nums, 8) << endl;
  cout << sol.searchRange(nums, 6) << endl;
}
