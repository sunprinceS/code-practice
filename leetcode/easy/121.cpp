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
    int maxProfit(vector<int>& prices) {
      if (prices.size() < 2) return 0;
      vector<int> deltas(prices.size()-1);
      for(int i=0; i< deltas.size(); ++i){
        deltas[i] = prices[i+1] - prices[i];
      }
      vector<int> dp(deltas.size());
      int ret = dp[0] = max(0, deltas[0]);
      for(int i=1;i<deltas.size();++i){
        dp[i] = max(deltas[i], deltas[i] + dp[i-1]);
        ret = max(dp[i], ret);
      }
      return ret;
    }
};

int main(){
  //vector<int> vec({10,4,3,2,1});
  //vector<int> vec({7,1,5,3,6,4});
  vector<int> vec({1,2,4});
  Solution sol;
  cout << sol.maxProfit(vec) << endl;
}
