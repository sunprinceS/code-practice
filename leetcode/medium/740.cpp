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
    int deleteAndEarn(vector<int>& nums) {
      if (nums.empty()) return 0;
      sort(nums.begin(), nums.end());
      vector<pair<int,int>> ns;

      ns.push_back({nums[0],nums[0]});

      for(int i=1; i< nums.size(); ++i){
        if(ns.back().first == nums[i]) ns.back().second += nums[i];
        else ns.push_back({nums[i],nums[i]});
      }

      int n = ns.size();
      if( n == 1) return ns[0].second;
      else if(n == 2) return (ns[1].first == ns[0].first + 1)?max(ns[0].second, ns[1].second):ns[0].second + ns[1].second;
      else{
        vector<int> dp(n);
        dp[0] = ns[0].second;
        dp[1] = (ns[1].first == ns[0].first + 1)?ns[1].second: dp[0] + ns[1].second;
        int m = dp[0];
        for(int i=2; i< n; ++i){
          if(ns[i].first == ns[i-1].first + 1) dp[i] = m + ns[i].second;
          else dp[i] = max(m,dp[i-1]) + ns[i].second;

          m = max(m, dp[i-1]);
        }
        return max(dp[n-1], dp[n-2]);
      }
    }
};

int main(){
  Solution sol;
  vector<int> ns;
  ns = {3,4,2,100};
  cout << sol.deleteAndEarn(ns) << endl;
  ns = {2,2,3,3,3,4};
  cout << sol.deleteAndEarn(ns) << endl;
  ns = {3,1};
  cout << sol.deleteAndEarn(ns) << endl;
  ns = {1,6,3,3,8,4,8,10,1,3};
  cout << sol.deleteAndEarn(ns) << endl;
}
