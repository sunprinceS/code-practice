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

//This problem is equivalent to find # comb s.t summation is (sum + S) / 2
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      int n = nums.size();
      if(abs(S) > 1000) return 0;
      if (n == 1) return int(nums[0] == abs(S));
      else{
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = (sum + S);

        if (target % 2) return 0;
        target /= 2;
        int num_zeros = int(nums[0] == 0);

        vector<vector<int>> dp(n);
        for(auto& v: dp) v = vector<int> (target+1,0);
        for(int i=0; i<n; ++i) dp[i][0] = 1;

        int cur_bound = nums[0];
        dp[0][nums[0]] = 1;

        for(int i=1; i<n;++i){
          dp[i] = dp[i-1];
          if(nums[i] == 0) ++num_zeros;
          else{
            cur_bound = min(nums[i] + cur_bound, target);
            for(int c = cur_bound; c>= nums[i]; --c){
              dp[i][c] = dp[i-1][c] + dp[i-1][c-nums[i]];
            }
          }
        }
        return dp[n-1][target] * pow(2, num_zeros);
      }
    }
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {1,1,1,1,1};
  cout << sol.findTargetSumWays(nums, 3) << endl;
  nums = {1,1,1,1};
  cout << sol.findTargetSumWays(nums, 0) << endl;
  nums = {-1000};
  cout << sol.findTargetSumWays(nums, 1000) << endl;
}
