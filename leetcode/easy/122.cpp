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
        vector<int> deltas(prices.size()-1);
        for(size_t i=0;i<deltas.size();++i){
          deltas[i] = prices[i+1]-prices[i];
        }
        int sum = 0;
        for(auto& d: deltas){
          if(d > 0) sum += d;
        }
        return sum;
    }
};

int main(){
  Solution sol;
}
