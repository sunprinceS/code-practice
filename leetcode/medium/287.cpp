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

class Solution{
  public:
  //Method1 : 如果可以更改值的話
  //int findDuplicate(vector<int>& nums) {
    //for(size_t i=0;i<nums.size();++i){
      //if(nums[abs(nums[i])-1] < 0) return abs(nums[i]);
      //else nums[abs(nums[i])-1] *= -1; 
    //}
  //}
  // Method2 : 利用鴿籠的二分搜，去看哪個區間的元素有多
  //int findDuplicate(vector<int>& nums){
    //int low = 1,high = nums.size()-1;
    //int mid;
    //int cnt;
    //while(low <= high){
      //cnt = 0;
      //mid = (low + high) /2;
      //for(auto n: nums){
        //if(n <= mid) ++cnt;
      //}
      //if(cnt <= mid) low = mid +1;
      //else high = mid - 1;
    //}
    //return low;
  //}
  // Method3 : 很厲害的 O(n) 算法 -> see https://sunprinces.github.io/learning/2018/03/leetcode-287---find-the-duplicate-number/
  int findDuplicate(vector<int>& nums) {
    int t = nums[0];
    int h = nums[nums[0]];
    while (t != h){
      t = nums[t];
      h = nums[nums[h]];
    }

    h = 0;
    while (t != h){
      t = nums[t];
      h = nums[h];
    }
    return t;
  }
};
int main(){
  Solution sol;
  vector<int> nums = {1,2,2};
  cout << sol.findDuplicate(nums) << endl;
}
