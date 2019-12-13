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
    int coinChange(vector<int>& coins, int amount) {
      if (amount == 0) return 0;
      if (coins.empty()) return -1;

      vector<int> dp(amount+1, -1);

      dp[0] = 0;
      for(int i=1; i<=amount; ++i){
        for(auto &c: coins){
          if(i >= c && dp[i-c] >=0){
            if (dp[i] == -1) dp[i] = dp[i-c] + 1;
            else dp[i] = min(dp[i], dp[i-c] + 1);
          }
        }
      }
      return dp[amount];
    }
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {1,2,5};
  cout << sol.coinChange(nums, 11) << endl;
  nums = {2};
  cout << sol.coinChange(nums, 3) << endl;
  nums = {4,3};
  cout << sol.coinChange(nums, 9) << endl;
  
}
