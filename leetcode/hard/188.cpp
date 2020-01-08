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
    int maxProfit(int k, vector<int>& prices) {
      if (prices.size() < 2) return 0;
      //if (prices.size() == 2) return max(prices[1] - prices[0], 0);
      vector<int> deltas(prices.size() - 1);
      for(int i = 0; i < deltas.size(); ++i) deltas[i] = prices[i+1] - prices[i];

      vector<vector<int>> dp(k);
      for(auto& v: dp){
        v = vector<int> (deltas.size());
        v[0] = deltas[0];
      }

      vector<int> ms(k-1);
      for(auto& m :ms) m = INT_MIN;

      int ret = deltas[0];
      for(int i=1; i< deltas.size(); ++i){
        dp[0][i] = max(deltas[i], dp[0][i-1] + deltas[i]);
        for(int j=2; j<=k; ++j){
          if(i >= j){
            ms[j-2] = max(ms[j-2], dp[j-2][i-j]);
            dp[j-1][i] = max(ms[j-2] + deltas[i], dp[j-1][i-1] + deltas[i]);
          }
          else{
            dp[j-1][i] = dp[j-1][i-1] + deltas[i];
          }
          if(dp[j-1][i] > ret) ret = dp[j-1][i];
        }
        if(dp[0][i] > ret) ret = dp[0][i];
      }
      return max(0,ret);
    }
};

int main(){
  Solution sol;
  vector<int> prices = {2,4,1};
  //vector<int> prices = {7,6,4,3,1};
  //vector<int> prices = {1,2,3,4,5};
  //vector<int> prices = {3,3,5,0,0,3,1,4};
  cout << sol.maxProfit(2,prices) << endl;
  prices = {3,2,6,5,0,3};
  cout << sol.maxProfit(2,prices) << endl;
}
