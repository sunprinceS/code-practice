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
    int combinationSum4(vector<int>& nums, int target) {
      if (target == 0 || nums.empty()) return 0;
      
      vector<unsigned int> f(target + 1,0);
      f[0] = 1;
      for(int i=1;i<=target;++i){
        for(auto& n:nums){
          if (n <= i) f[i] += f[i-n];
        }
      }
      return f[target]; 
    }
};


int main(){
  Solution sol;

  vector<int> nums;
  nums = {3,33,333};
  cout << sol.combinationSum4(nums, 10000) << endl;
}
