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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> DP(amount+1,-1);
        DP[0] = 0;
        for(int n=1;n<=amount;++n){
          for(int c:coins){
            if(n >= c && DP[n-c] != -1){
              DP[n] = DP[n] > 0 ? min(DP[n],DP[n-c] + 1):DP[n-c]+1;
            }
          }
        }
        return DP[amount];
    }
};

int main(){
  Solution sol;
  vector<int> nums({2});
  cout << sol.coinChange(nums,11) << endl;
}
