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
      if(prices.size() <= 1) return 0;
      int cash = 0, hold = -prices[0];
      for(auto& p:prices){
        cash = max(cash, hold + p - fee);
        hold = max(hold, cash - p);
      }
      return cash;
    }
};

int main(){
  Solution sol;
}
