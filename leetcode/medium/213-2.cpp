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
      if (n == 0) return 0;
      else if(n == 1) return nums[0];
      else if(n == 2) return max(nums[0], nums[1]);
      else if (n == 3) return max(nums[0],max(nums[1], nums[2]));
      else{
        // first house is stolen, wo we cannot steal last house
        int ret;
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = INT_MIN;
        int m = dp[0];
        for(int i=2; i< n-1; ++i){
          dp[i] = m + nums[i];
          m = max(m, dp[i-1]);
        }
        ret = max(dp[n-2], dp[n-3]);

        //first house is not stolen
        dp[0] = INT_MIN;
        dp[1] = nums[1];
        dp[2] = nums[2];
        m = dp[1];
        for(int i=3; i<n;++i){
          dp[i] = m + nums[i];
          m = max(m, dp[i-1]);
        }
        return max(ret, max(dp[n-1],dp[n-2]));
      }
    }
};



int main(){
}
