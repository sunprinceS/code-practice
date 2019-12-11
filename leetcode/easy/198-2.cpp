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
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n);
      if (n == 0) return 0
      else if(n == 1) return nums[0];
      else if(n == 2) return max(nums[0], nums[1]);
      else{
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int m = dp[0];
        for(int i=2; i< n; ++i){
          dp[i] = m + nums[i];
          m = max(m, dp[i-1]);
        }
        return max(dp[n-1], dp[n-2]);
      }
    }
};

int main(){
  Solution sol;
  vector<int> nums = {1,2,3,1};
  cout << sol.rob(nums) << endl;
  nums = {2,7,9,3,1};
  cout << sol.rob(nums) << endl;
}
