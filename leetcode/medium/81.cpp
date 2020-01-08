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
    bool search(vector<int>& nums, int target) {
      if (nums.empty()) return false;
      return sub_search(nums, target, 0, nums.size() - 1);
    }

    bool sub_search(vector<int>& nums, int target, int lb, int rb){
      // current range is not sorted
      if(lb == rb) return nums[lb] == target;
      if(lb == rb - 1) return nums[lb] == target || nums[rb] == target;

      int mid = lb + (rb - lb) / 2;
      int res;
      if (nums[mid] == target) return true;

      if(nums[lb] < nums[mid]) res = binary_search(nums, target, lb, mid-1);
      else res = sub_search(nums, target, lb, mid-1);

      if(res) return true;

      if(nums[rb] > nums[mid]) return binary_search(nums, target, mid+1, rb);
      else return sub_search(nums, target, mid+1, rb);

    }

    bool binary_search(vector<int>& nums, int target, int lb, int rb){
      if(lb == rb) return nums[lb] == target;
      if(lb == rb - 1) return nums[lb] == target || nums[rb] == target;

      int mid = lb + (rb - lb ) / 2;
      if(nums[mid] == target) return true;
      else if(nums[mid] > target) return binary_search(nums, target, lb, mid-1);
      else return binary_search(nums, target, mid+1, rb);
    }
};
//class Solution {
//public:
    //bool search(vector<int>& nums, int target) {
      //int lb =0, rb = nums.size()-1;
      //int mid;
      //if(nums.empty()) return false;
      //if(nums.size() == 1) return nums[0] == target;
        
      //while(lb < rb){
        //mid = (lb + rb) / 2;
        //if(nums[rb] > nums[lb]) break;
        //else{
          //if(nums[mid] >= nums[lb]) lb = mid + 1;
          //else rb = mid;
        //}
      //}
      
      //int shift = lb;
      //while(shift > 0){
        //if(nums[shift - 1] == nums[shift]) --shift;
        //else break;
      //}
      //cout << "Shifting\t" << shift << endl;

      //// now shift is fixed
      //lb = 0, rb = nums.size()-1;
      //int rotate_mid;
      //if(nums[shift] > target || nums[(nums.size() + shift - 1) % nums.size()] < target) return false;
    
      //while(lb < rb){
        //mid = (lb + rb) / 2;
        //rotate_mid = (mid + shift) % nums.size();
        //if(nums[rotate_mid] > target) rb = mid;
        //else if(nums[rotate_mid] < target) lb = mid + 1;
        //else return true;
      //}
      //return nums[(lb + shift)%nums.size()] == target;
    //}
//};


int main(){
  Solution sol;
  vector<int> nums;
  //nums = {2,5,6,0,0,1,2};
  //cout << sol.search(nums, 0) << endl;
  //cout << sol.search(nums, 3) << endl;
  //cout << "===============" << endl;

  ////nums = {0,0,0,0,1,1,1,1,12,3,4,10};
  //nums = {1,1,1,1,1,2,4,0,0,1};
  //cout << sol.search(nums, 0) << endl;
  //cout << sol.search(nums, 1) << endl;
  //cout << sol.search(nums, 3) << endl;
  //cout << "===============" << endl;

  //nums = {1,3};
  //cout << sol.search(nums,1) << endl;
  //cout << sol.search(nums,3) << endl;
  //cout << "===============" << endl;

  //nums = {2,1,1,2,2,2,2};
  //cout << sol.search(nums, 1) << endl;
  //cout << sol.search(nums, 2) << endl;
  //cout << "===============" << endl;

  nums = {2,2,2,3,1};
  cout << sol.search(nums, 1) << endl;

  nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  cout << sol.search(nums, 2) << endl;
}
