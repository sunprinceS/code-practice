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
    int smallestDistancePair(vector<int>& nums, int k) {
        
      sort(nums.begin(), nums.end());
      if(nums.size() == 1) return nums[1] - nums[0];
      
      int lb = 0, rb = nums.back() - nums[0];
      int mid;
      int n_smaller;
      int s = 1;

      while(lb < rb){
        mid = (lb + rb) / 2;
        n_smaller = 0;


        for(int i=0; i< nums.size() - 1; ++i){
          s = distance(nums.begin() + i, upper_bound(nums.begin() + s + i-1, nums.end(), mid + nums[i] )) - 1;
          n_smaller += s;
          //n_smaller += distance(nums.begin() + i, upper_bound(nums.begin() + i, nums.end(), mid+ nums[i])) - 1;
        }
        if(n_smaller < k) lb = mid + 1;
        else rb = mid - 1;
      }
      return lb;
    } 
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {62,100,4};
  cout << sol.smallestDistancePair(nums, 1) << endl;
  cout << sol.smallestDistancePair(nums, 2) << endl;
  cout << sol.smallestDistancePair(nums, 3) << endl;
}
