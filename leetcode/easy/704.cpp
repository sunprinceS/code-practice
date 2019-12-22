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
    int search(vector<int>& nums, int target) {
      auto p = equal_range(nums.begin(), nums.end(), target);
      int lb = p.first - nums.begin();
      int ub = p.second - nums.begin();
      if (lb == ub) return -1;
      else return lb;
        
    }
};

int main(){
  Solution sol;
  vector<int> nums;
  nums = {-1,0,3,5,9,12};
  cout << sol.search(nums, 9) << endl;
  cout << sol.search(nums, 2) << endl;
}
