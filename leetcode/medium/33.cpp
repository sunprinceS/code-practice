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
    //int search(vector<int>& nums, int target) {
      //// find rotating point
      //int lb = 0, rb = nums.size()-1;
      //int shift, mid;
      //if(nums.empty()) return -1;
      //if(nums[rb] > nums[lb]) shift = 0;
      //else{
          //while(nums[lb] > nums[rb]){
              //mid = (lb + rb) / 2;
              //if(nums[mid] > nums[lb]) lb = mid + 1;
              //else rb = mid;
          //}
          //if (lb < nums.size() - 1 && nums[lb] > nums[lb + 1]) shift = lb + 1;
          //else shift = lb;
      //}

      //lb = 0;
      //rb = nums.size();
      //int rotate_mid;
      //while(lb < rb){
        //mid = (lb + rb) / 2;
        //rotate_mid = (((lb + rb) / 2) + shift) % nums.size();
        //if(nums[rotate_mid] > target) rb = mid;
        //else if(nums[rotate_mid] < target) lb = mid + 1;
        //else return rotate_mid;
      //}
      //return -1;
    //}
//};

//class Solution {
//public:
    //int search(vector<int>& nums, int target) {
      //int lb = 0, rb = nums.size() - 1;
      //int mid;
      //if(nums.empty()) return -1;
      //if(nums.size() == 1) return nums[0] == target ? 0: -1;
      //while(lb < rb){
        //mid = (lb + rb) / 2;

        //if(nums[mid] == target) return mid;


        //if(nums[lb] <= nums[mid]){ // left part is ascending
          //if(nums[lb] <= target && target < nums[mid]) rb = mid;
          //else lb = mid + 1;
        //}
        //else{ // right part is ascending
          //if(nums[mid] < target && target <= nums[rb]) lb = mid + 1;
          //else rb = mid;
        //}
      //}  
      //return nums[lb] == target ? lb : -1;
    //}
//};
class Solution {
public:
    int search(vector<int>& nums, int target) {
      if (nums.empty()) return -1;
      return sub_search(nums, target, 0, nums.size() - 1);
    }

    int sub_search(vector<int>& nums, int target, int lb, int rb){
      // current range is not sorted
      if(lb >= rb) return nums[lb] == target? lb:-1;

      int mid = lb + (rb - lb) / 2;
      int res;
      if (nums[mid] == target) return mid;
      else if(nums[lb] < nums[mid]){ // left part is sorted
        res = binary_search(nums, target, lb, mid);
        if(res != -1) return res;
        return sub_search(nums, target, mid+1, rb);
      }
      else{
        res = binary_search(nums, target, mid+1, rb);
        if(res != -1) return res;
        return sub_search(nums, target, lb, mid);
      }
    }

    int binary_search(vector<int>& nums, int target, int lb, int rb){
      if(lb >= rb) return nums[lb] == target? lb:-1;

      int mid = lb + (rb - lb ) / 2;
      if(nums[mid] == target) return mid;
      else if(nums[mid] > target) return binary_search(nums, target, lb, mid-1);
      else return binary_search(nums, target, mid+1, rb);
    }
};


int main(){
  Solution sol;
  vector<int> nums;
  nums = {4,5,6,7,0,1,2};
  cout << sol.search(nums, 9) << endl; // -1
  cout << sol.search(nums, 6) << endl; // 2
  cout << sol.search(nums, 2) << endl; // 6
  cout << "==============" << endl;

  nums = {3,1};
  cout << sol.search(nums,1) << endl; // 1
  cout << sol.search(nums,3) << endl; // 0
  cout << "==============" << endl;

  nums = {1,3};
  cout << sol.search(nums, 1) << endl; // 0
  cout << sol.search(nums, 3) << endl; // 1
}
