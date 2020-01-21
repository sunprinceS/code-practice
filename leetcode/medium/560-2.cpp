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

int main(){
  Solution sol;
  vector<int> nums;
  nums = {1,1,1,1,1};
  cout << sol.subarraySum(nums,2) << endl;

  nums = {0,1};
  cout << sol.subarraySum(nums, 1) << endl;

  nums = {1};
  cout << sol.subarraySum(nums,0) << endl;
  cout << sol.subarraySum(nums, 1) << endl;
}
