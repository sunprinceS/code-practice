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

// O(n * target)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      if ( n == 1 ) return false;

      int sum = accumulate(nums.begin(), nums.end(), 0);
      if (sum % 2) return false;
      int target = sum / 2;

      vector<vector<bool>> dp(n);
      for(auto& v: dp) v = vector<bool>(target+1);

      // boundary condition
      for(int i=0; i<n;++i) dp[i][0] = true;
      if(nums[0] == target) return true;
      if(nums[0] > target) return false;

      dp[0][nums[0]] = true;

      int cur_bound = nums[0];
      for(int i=1; i<n;++i){
        if (nums[i] > target) return false;
        if(nums[0] == target) return true;
        dp[i] = dp[i-1];

        cur_bound += nums[i];
        for(int c=min(cur_bound,target); c>=nums[i]; --c){
          if(dp[i-1][c-nums[i]]) dp[i][c] = true;
          if(c == target && dp[i][c]) return true;
        }
      }
      return false;
    }
};

// dfs recursion: O(n!) -> TLE
//class Solution {
//public:
    //bool canPartition(vector<int>& nums) {
      //if (nums.size() == 1) return false;
      //sort(nums.begin(), nums.end());
      
      //int sum = accumulate(nums.begin(), nums.end(), 0);
      //if (sum % 2) return false;
      
      //return dfs(nums, sum/2, 0);
    //}

    //bool dfs(vector<int>& nums, int target, int pos){
      //if (target == 0) return true;
      //for(int i=pos; i< nums.size();++i){
        //if(nums[i] > target) break;
        //else{
          //if (dfs(nums, target - nums[i], i+1)) return true;
        //}
      //}
      //return false;
    //}
//};


int main(){
  Solution sol;
  vector<int> nums;
  nums = {1,2,5};
  cout << sol.canPartition(nums) << '\t' << false << endl;
  nums = {1,2,3,5};
  cout << sol.canPartition(nums) << '\t' << false <<  endl;
  nums = {1,2,3,4};
  cout << sol.canPartition(nums) << '\t' << true <<  endl;
  nums = {1,5,11,5};
  cout << sol.canPartition(nums) << '\t' << true <<  endl;
  nums = {1,1,1,1,1,4};
  cout << sol.canPartition(nums) << '\t' << false <<  endl;
  nums = {23,13,11,7,6,5,5};
  cout << sol.canPartition(nums) << '\t' << true <<  endl;
}
