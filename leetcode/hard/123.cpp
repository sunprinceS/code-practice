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
    int maxProfit(vector<int>& prices) {
      if (prices.size() < 2) return 0;
      //if (prices.size() == 2) return max(prices[1] - prices[0], 0);
      vector<int> deltas(prices.size() - 1);
      for(int i = 0; i < deltas.size(); ++i) deltas[i] = prices[i+1] - prices[i];

      vector<vector<int>> dp(2);
      dp[0] = vector<int> (deltas.size());
      dp[1] = vector<int> (deltas.size());

      dp[0][0] = deltas[0];
      dp[1][0] = deltas[0];

      int m = INT_MIN;
      int ret = deltas[0];
      for(int i=1; i< deltas.size(); ++i){
        dp[0][i] = max(deltas[i], dp[0][i-1] + deltas[i]);
        if (i >= 2){
          m = max(m, dp[0][i-2]);
          dp[1][i] = max(m + deltas[i], dp[1][i-1] + deltas[i]);
        }
        else{
          dp[1][i] = dp[1][i-1] + deltas[i];
        }

        ret = max(ret, dp[0][i]);
        ret = max(ret, dp[1][i]);
      }
      return max(0,ret);
    }
};

int main(){
  Solution sol;
  vector<int> prices = {1,4,2};
  //vector<int> prices = {7,6,4,3,1};
  //vector<int> prices = {1,2,3,4,5};
  //vector<int> prices = {3,3,5,0,0,3,1,4};
  cout << sol.maxProfit(prices) << endl;
}
