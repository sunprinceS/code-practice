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

class Solution{
  public:
    int maxProfit(vector<int>& prices, int fee) {
      if(prices.size() < 2) return 0;
      int ret = 0;
      vector<vector<int>> dp(2);
      dp[0] = vector<int>(prices.size());
      dp[1] = vector<int>(prices.size());

      dp[0][0] = 0; 
      dp[1][0] = -1 * prices[0];

      for(int i=1; i < prices.size(); ++i){
        dp[0][i] = max(prices[i] + dp[1][i-1]-fee, dp[0][i-1]);
        dp[1][i] = max(dp[0][i-1] - prices[i], dp[1][i-1]);

        ret = max(ret, dp[0][i]);
      }
      return ret;
    }
};

int main(){
  Solution sol;
  vector<int> prices=  {1, 3, 2, 8, 4, 9};
  cout << sol.maxProfit(prices, 2) << endl;
}
