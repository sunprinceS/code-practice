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
        return max(0,maxSubArrSum(deltas,0,deltas.size()-1));
    }
    int maxSubArrSum(vector<int>& v,int l,int r){
        if(l == r) return v[l];

        int m = (l+r)/2;
        return max(max(maxSubArrSum(v,l,m),maxSubArrSum(v,m+1,r)),maxCrossSum(v,l,r,m));
    }
    int maxCrossSum(vector<int>& v,int l,int r,int m){
      int sum = 0;
      int l_sum = INT_MIN;
      for(int i=m;i>=l;--i){
        sum += v[i];
        if(sum > l_sum)
          l_sum = sum;
      }
      sum = 0;
      int r_sum = INT_MIN;
      for(int i=m+1;i<=r;++i){
        sum += v[i];
        if(sum > r_sum)
          r_sum = sum;
      }
      return r_sum + l_sum;
    }
};

int main(){
  //vector<int> vec({10,4,3,2,1});
  vector<int> vec({3,2,10,1,4});
  Solution sol;
  cout << sol.maxProfit(vec) << endl;
}
