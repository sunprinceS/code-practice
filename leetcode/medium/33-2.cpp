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
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      return sub_search(nums, 0, nums.size()-1, target);
    }

private:
    int sub_search(vector<int>& nums, int lb, int rb, int target){ // rotated sorted
      if (lb >= rb) return nums[lb] == target? lb:-1;
      int ret;
      int mid = (lb + rb) / 2;

      if(nums[mid] == target) return mid;

      if(nums[mid] > nums[lb]) ret = binary_search(nums, lb, mid-1, target);
      else ret = sub_search(nums, lb, mid-1, target);

      if(ret != -1) return ret;

      if(nums[mid] < nums[rb]) ret = binary_search(nums, mid+1, rb, target);
      else ret = sub_search(nums, mid+1, rb , target);

      return ret;
    }

    int binary_search(vector<int>& nums, int lb, int rb, int target){ // [lb, rb] is sorted
      if(lb >= rb) return nums[lb] == target? lb:-1;
      int mid;
      while(lb < rb){
        mid = (lb + rb) / 2;
        if(nums[mid] > target) rb = mid - 1;
        else if(nums[mid] < target) lb = mid + 1;
        else return mid;
      }
      return nums[lb] == target? lb: -1;
    }
};



int main(){
  Solution sol;
  vector<int> nums;

  nums = {4,5,6,7,0,1,2};
  cout << sol.search(nums, 0) << endl; // 4
  cout << sol.search(nums, 3) << endl; // -1

  nums = {0,1,2,4,5,6};
  cout << sol.search(nums, 3) << endl; // -1
  cout << sol.search(nums, 4) << endl; // 3

  nums = {1};
  cout << sol.search(nums, 1) << endl;
  cout << sol.search(nums, 2) << endl;
}
