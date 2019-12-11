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

      int s = 0, ns = 0, h = -prices[0];
      int tmp_s, tmp_ns; 
      for(int i=1; i< prices.size(); ++i){
        tmp_s = s;
        tmp_ns = ns;

        s = h + prices[i];
        ns = max(tmp_s, ns);
        h = max(h,tmp_ns - prices[i]);
      }
      return max(s, ns);

    }
};

int main(){
  Solution sol;
  vector<int> prices = {1,2,4};
  cout << sol.maxProfit(prices) << endl;
}
