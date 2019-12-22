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
      int lb =0, rb = nums.size()-1;
      int mid;
      while(lb < rb){
        mid = (lb + rb) / 2;
        if(nums[rb] > nums[lb]) return nums[lb];// current range is sorted
        else{
          if(nums[mid] >= nums[lb]) lb = mid + 1;
          else rb = mid;
        }
      }
      return nums[lb];
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
