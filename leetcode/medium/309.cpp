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
      if(prices.size() <= 1) return 0;
      int cash_buy = 0;
      int cash_nobuy = 0;
      int hold = -prices[0];
      int cb,cnb,h;
      for(auto& p:prices){
        cb = cash_buy;
        cnb = cash_nobuy;
        h = hold;
        
        cash_buy = h+p;
        cash_nobuy = max(cb,cnb);
        hold = max(h,cnb-p);
      }
      return max(cash_buy,cash_nobuy);
    }
};

int main(){
  Solution sol;
}
