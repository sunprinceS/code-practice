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
    int minCostClimbingStairs(vector<int>& cost) {
      vector<int> arr(cost.size()+1);
      arr[0] = 0;
      arr[1] = 0;
      for(size_t i=2;i<=cost.size();++i){
        arr[i] = min(arr[i-1] + cost[i-1],arr[i-2] + cost[i-2]);
      }
      return arr[cost.size()];
    }
    
};

int main(){
  Solution sol;
  vector<int> cost = {10,15,20};
  //vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << sol.minCostClimbingStairs(cost) << endl;
}
