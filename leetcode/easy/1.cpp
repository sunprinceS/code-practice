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
    // from the description
    // * exactly one solution
    // * cannot same element twice
    // -> no duplicate number in nums!
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> ns;
      ns.reserve(nums.size());
      for(int i=0; i< nums.size(); ++i){
        ns.insert({nums[i],i});
        auto got = ns.find(target - nums[i]);
        if(got != ns.end() && got -> second != i){
          return {i, got-> second};
        }
      }
      return {0,0};
    }
};


int main(){
  Solution sol;
  vector<int> nums;
  nums = {3,2,4};
  cout << sol.twoSum(nums,6) << endl;
}
